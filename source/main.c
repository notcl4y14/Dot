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

	// Initializing Dot Frame
	dot_frame = DotFrame_Create();
	sdl_frame = DotFrame_GetSDLFrame(dot_frame);

	// Initializing SDL Frame
	SDLFrame_Init(sdl_frame);

	// Initializing a Window
	SDLFrame_CreateWindow(
		sdl_frame,
		"Dot", 800, 600,
		SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE);

	SDLFrame_ShowWindow(sdl_frame);

	// Starting Dot Frame
	DotFrame_Start(dot_frame);

	while (DotFrame_IsRunning(dot_frame))
	{
		// Process Events
		while (SDLFrame_PollEvent(sdl_frame))
		{
			switch (sdl_frame->event.type)
			{
				case SDL_EVENT_QUIT:
					DotFrame_Stop(dot_frame);
					break;
			}
		}

		SDL_Delay(10);
	}

	// Freeing Frames
	SDLFrame_Destroy(sdl_frame);
	DotFrame_Delete(dot_frame);
	return 0;
}