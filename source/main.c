#include <Dot/main.h>
#include <Dot/dot_frame.h>
#include <Dot/sdl_frame.h>

#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdint.h>

DotFrame* dot_frame;
SDLFrame* sdl_frame;

int32_t main (int32_t argc, char** argv)
{
	printf("Hello World!\n");

	Init();
	Loop();
	Quit();

	return 0;
}

// 

void Init ()
{
	// Initializing Dot Frame
	dot_frame = DotFrame_Create();
	sdl_frame = SDLFrame_Create();

	// Initializing SDL Frame
	SDLFrame_InitSDL(sdl_frame);

	// Initializing a Window
	const char* title = "Dot";
	const uint32_t width = 800;
	const uint32_t height = 600;
	const SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;

	SDLFrame_CreateWindow(sdl_frame, title, width, height, flags);

	// Initializing Runner
	Runner_SetTargetLPS(dot_frame->runner, 60);

	// Initializing CellChunk
	CellChunk_Init(dot_frame->chunk, 32, 32);
	CellChunk_SetCell(dot_frame->chunk, 10, 10, (Cell){Sand, {255, 255, 0, 255}});
}

void Quit ()
{
	// Freeing Frames
	SDLFrame_QuitSDL(sdl_frame);
	DotFrame_Delete(dot_frame);
}

void Loop ()
{
	Runner* runner = dot_frame->runner;

	// Starting Dot Frame
	DotFrame_Start(dot_frame);

	while (DotFrame_IsRunning(dot_frame))
	{
		// Process Events
		ProcessEvents();

		// Update & Render
		Update();
		Render();

		// Next Tick
		DotFrame_Tick(dot_frame);

		// Print FPS each second
		if (runner->loop_count % runner->lps_target == 0)
		{
			printf("FPS: %d\n", runner->lps_current);
		}

		// Delay
		SDL_Delay(1000 / runner->lps_target);
	}
}

// 

void ProcessEvents ()
{
	while (SDLFrame_PollEvent(sdl_frame))
	{
		switch (sdl_frame->event.type)
		{
			case SDL_EVENT_QUIT:
				DotFrame_Stop(dot_frame);
				break;
		}
	}
}

void Update ()
{
	return;
}

void Render ()
{
	SDL_Renderer* renderer = sdl_frame->renderer;
	SDL_Rect rect;
	SDL_FRect frect;

	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);

	// Render CellChunk
	{
		CellChunk* cell_chunk = dot_frame->chunk;
		Cell cell;

		uint32_t scale = 10;

		// Render CellChunk borders
		frect.x = 0;
		frect.y = 0;
		frect.w = cell_chunk->width * scale;
		frect.h = cell_chunk->height * scale;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderRect(renderer, &frect);

		// Render CellChunk cells
		for (uint32_t i = 0; i < cell_chunk->area; i++)
		{
			cell = cell_chunk->cells[i];

			if (cell.id == 0)
			{
				continue;
			}

			frect.x = (i % cell_chunk->width) * scale;
			frect.y = (i / cell_chunk->width) * scale;
			frect.w = scale;
			frect.h = scale;

			SDL_SetRenderDrawColor(renderer, cell.color[0], cell.color[1], cell.color[2], cell.color[3]);
			SDL_RenderFillRect(renderer, &frect);
		}
	}

	SDL_RenderPresent(renderer);
}