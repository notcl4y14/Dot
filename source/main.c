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

	init();
	loop();
	quit();

	return 0;
}

// 

void init ()
{
	// Initializing Dot Frame
	dot_frame = DotFrame_Create();
	sdl_frame = DotFrame_GetSDLFrame(dot_frame);

	// Initializing SDL Frame
	SDLFrame_Init(sdl_frame);

	// Initializing a Window
	const char* title = "Dot";
	const uint32_t width = 800;
	const uint32_t height = 600;
	const SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;

	SDLFrame_CreateWindow(sdl_frame, title, width, height, flags);

	// Initializing Runner
	Runner_SetTargetLPS(dot_frame->runner, 60);
}

void quit ()
{
	// Freeing Frames
	SDLFrame_Destroy(sdl_frame);
	DotFrame_Delete(dot_frame);
}

void loop ()
{
	// Starting Dot Frame
	DotFrame_Start(dot_frame);

	while (DotFrame_IsRunning(dot_frame))
	{
		// Process Events
		process_events();

		// Update & Render
		update();
		render();

		// Next Tick
		DotFrame_NextTick(dot_frame);

		// Print FPS
		if (dot_frame->runner->loop_count % 60 == 0)
		{
			printf("FPS: %d\n", dot_frame->runner->lps_current);
		}

		// Delay
		SDL_Delay(1000 / dot_frame->runner->lps_target);
	}
}

// 

void process_events ()
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

void update ()
{
	return;
}

void render ()
{
	SDL_Renderer* renderer = dot_frame->sdl_frame->renderer;

	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}