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
	CellChunk_Init(dot_frame->cell_chunk, 32, 32);
	CellChunk_SetCell(dot_frame->cell_chunk, 10, 10, (Cell){Sand, {255, 255, 0, 255}});
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
	// Update CellChunk
	CellChunk_Update(dot_frame->cell_chunk);
}

void Render ()
{
	SDL_Renderer* renderer = sdl_frame->renderer;
	SDL_Rect rect;
	SDL_FRect frect;

	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);

	// Render CellChunk
	CellChunk_Render(dot_frame->cell_chunk, sdl_frame, 10);

	SDL_RenderPresent(renderer);
}