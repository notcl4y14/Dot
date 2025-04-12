#include <Dot/sdl_frame.h>

#include <SDL3/SDL.h>

#include <stdlib.h>
#include <stdint.h>

SDLFrame* SDLFrame_Create ()
{
	SDLFrame* sdl = malloc(sizeof(SDLFrame));

	sdl->window = NULL;
	sdl->renderer = NULL;

	return sdl;
}

void      SDLFrame_Delete (SDLFrame* sdl)
{
	if (sdl->renderer != NULL)
	{
		SDL_DestroyRenderer(sdl->renderer);
	}

	if (sdl->window != NULL)
	{
		SDL_DestroyWindow(sdl->window);
	}
}

void SDLFrame_Init (SDLFrame* sdl)
{
	SDL_Init(SDL_INIT_VIDEO);
}

void SDLFrame_Free (SDLFrame* sdl)
{
	SDL_Quit();
}

void SDLFrame_CreateWindow (SDLFrame* sdl, const char* title, uint32_t width, uint32_t height, SDL_WindowFlags flags)
{
	sdl->window = SDL_CreateWindow(title, width, height, flags);
	sdl->renderer = SDL_CreateRenderer(sdl->window, NULL);
}

void SDLFrame_DeleteWindow (SDLFrame* sdl)
{
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
}

void SDLFrame_ShowWindow (SDLFrame* sdl)
{
	SDL_ShowWindow(sdl->window);
}

void SDLFrame_HideWindow (SDLFrame* sdl)
{
	SDL_HideWindow(sdl->window);
}

uint8_t SDLFrame_PollEvent (SDLFrame* sdl)
{
	return SDL_PollEvent(&sdl->event);
}