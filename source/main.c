#include <Dot/main.h>
#include <Dot/cells/cell.h>
#include <Dot/cells/cell_chunk.h>
#include <Dot/dot_frame.h>
#include <Dot/manager.h>
#include <Dot/runner.h>
#include <Dot/sdl_frame.h>

#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

DotFrame* _DotFrame;
SDLFrame* _SDLFrame;

int32_t main (int32_t argc, char** argv)
{
	printf("Hello World!\n");

	Init();
	Loop();
	Quit();

	return 0;
}

// 

// TODO: Move this somewhere else
void powder_logic (CellChunk* cell_chunk, Cell* cell, uint32_t x, uint32_t y)
{
	if (y == cell_chunk->height - 1)
	{
		return;
	}

	Cell* cell_bottom = CellChunk_GetCell(cell_chunk, x, y + 1);
	CellStats* cell_stats_bottom = Manager_GetUnitPtr(&_DotFrame->cell_manager, cell_bottom->id);

	if (cell_stats_bottom->is_empty == 1)
	{
		CellChunk_SwapCells(cell_chunk, x, y, x, y + 1);
		return;
	}

	Cell* cell_left = CellChunk_GetCell(cell_chunk, x - 1, y + 1);
	Cell* cell_right = CellChunk_GetCell(cell_chunk, x + 1, y + 1);
	CellStats* cell_stats_left = Manager_GetUnitPtr(&_DotFrame->cell_manager, cell_left->id);
	CellStats* cell_stats_right = Manager_GetUnitPtr(&_DotFrame->cell_manager, cell_right->id);

	if (x > 0 && cell_stats_left->is_empty == 1)
	{
		CellChunk_SwapCells(cell_chunk, x, y, x - 1, y + 1);
		return;
	}

	if (x < cell_chunk->width - 1 && cell_stats_right->is_empty == 1)
	{
		CellChunk_SwapCells(cell_chunk, x, y, x + 1, y + 1);
	}
}

void Init ()
{
	// Initializing Dot Frame
	_DotFrame = DotFrame_Create();
	_SDLFrame = SDLFrame_Create();

	// Initializing SDL Frame
	SDLFrame_InitSDL(_SDLFrame);

	// Initializing a Window and a Renderer
	const char* title = "Dot";
	const uint32_t width = 800;
	const uint32_t height = 600;
	const SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;

	SDLFrame_CreateWindow(_SDLFrame, title, width, height, flags);
	SDLFrame_CreateRenderer(_SDLFrame);

	// Initializing Runner
	Runner_SetTargetLPS(&_DotFrame->runner, 60);

	// Initializing CellChunk
	CellChunk_Init(&_DotFrame->cell_chunk, 64, 128);
	CellChunk_SetCell(&_DotFrame->cell_chunk, 10, 10, (Cell){CellID_Sand, 0xFFFF00FF});

	// Initializing Managers
	Manager_Init(&_DotFrame->cell_manager, sizeof(CellStats) * 4, sizeof(CellStats));

	{
		CellStats* air_stats = Manager_GetUnitPtr(&_DotFrame->cell_manager, 0);
		air_stats->id = 0;
		air_stats->colors_v = NULL;
		air_stats->colors_c = 0;
		air_stats->is_update = false;
		air_stats->is_render = false;
		air_stats->is_empty = true;
		air_stats->is_solid = false;
		air_stats->is_powder = false;
		air_stats->is_fluid = false;
		air_stats->method = NULL;
	}

	{
		CellStats* sand_stats = Manager_GetUnitPtr(&_DotFrame->cell_manager, 1);
		sand_stats->id = 1;
		sand_stats->colors_v = malloc(sizeof(uint32_t) * 4);
			sand_stats->colors_v[0] = 0xFFEC80FF;
			sand_stats->colors_v[1] = 0xFFE640FF;
			sand_stats->colors_v[2] = 0xFFF29CFF;
			sand_stats->colors_v[3] = 0xFFE659FF;
		sand_stats->colors_c = 4;
		sand_stats->is_update = true;
		sand_stats->is_render = true;
		sand_stats->is_empty = false;
		sand_stats->is_solid = false;
		sand_stats->is_powder = true;
		sand_stats->is_fluid = false;
		sand_stats->method = powder_logic;
	}
}

void Quit ()
{
	// Freeing Frames
	SDLFrame_DeleteRenderer(_SDLFrame);
	SDLFrame_DeleteWindow(_SDLFrame);
	SDLFrame_QuitSDL(_SDLFrame);
	DotFrame_Delete(_DotFrame);
}

void Loop ()
{
	Runner* runner = &_DotFrame->runner;

	// Starting Dot Frame
	DotFrame_Start(_DotFrame);

	while (DotFrame_IsRunning(_DotFrame))
	{
		// Process Events
		ProcessEvents();

		// Update & Render
		Update();
		Render();

		// Next Tick
		DotFrame_Tick(_DotFrame);

		// Print FPS each second
		if (runner->loop_count % runner->lps_target == 0)
		{
			printf("FPS: %d\n", runner->lps_current);

			char str[25];
			sprintf((char*)&str, "Dot | FPS: %d", runner->lps_current);

			SDL_SetWindowTitle(_SDLFrame->window, str);
		}

		// Delay
		SDL_Delay(1000 / runner->lps_target);
	}
}

// 

void ProcessEvents ()
{
	while (SDLFrame_PollEvent(_SDLFrame))
	{
		switch (_SDLFrame->event.type)
		{
			case SDL_EVENT_QUIT:
				DotFrame_Stop(_DotFrame);
				break;
		}
	}
}

void Update ()
{
	// Update CellChunk
	CellChunk_Update(&_DotFrame->cell_chunk);
	CellChunk_SetCell(&_DotFrame->cell_chunk,
		32.0f + (cos(SDL_GetTicks() / 100.0f)) * 10.0f,
		10,
		Cell_CreateFromStats(
			Manager_GetUnitPtr(&_DotFrame->cell_manager, CellID_Sand)));
}

void Render ()
{
	SDL_Renderer* renderer = _SDLFrame->renderer;

	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);

	// Render CellChunk
	CellChunk_Render(&_DotFrame->cell_chunk, 4);

	SDL_RenderPresent(renderer);
}