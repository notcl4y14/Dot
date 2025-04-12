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

	dot_frame = DotFrame_Create();
	sdl_frame = dot_frame->sdl_frame;

	SDLFrame_Init(sdl_frame);

	SDLFrame_CreateWindow(
		sdl_frame,
		"Dot", 800, 600,
		SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE);

	SDLFrame_ShowWindow(sdl_frame);

	dot_frame->running = 1;

	while (dot_frame->running)
	{
		while (SDLFrame_PollEvent(sdl_frame))
		{
			switch (sdl_frame->event.type)
			{
				case SDL_EVENT_QUIT:
					dot_frame->running = 0;
					break;
			}
		}

		SDL_Delay(10);
	}

	SDLFrame_Free(sdl_frame);
	DotFrame_Delete(dot_frame);
	return 0;
}