#ifndef DOT_SDLFRAME_H
#define DOT_SDLFRAME_H

#include <SDL3/SDL.h>

#include <stdint.h>

typedef struct SDLFrame
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
} SDLFrame;

SDLFrame* SDLFrame_Create ();
void      SDLFrame_Delete (SDLFrame* sdl);

void SDLFrame_InitSDL (SDLFrame* sdl);
void SDLFrame_QuitSDL (SDLFrame* sdl);

void SDLFrame_CreateWindow (SDLFrame* sdl, const char* title, uint32_t width, uint32_t height, SDL_WindowFlags flags);
void SDLFrame_DeleteWindow (SDLFrame* sdl);
void SDLFrame_ShowWindow (SDLFrame* sdl);
void SDLFrame_HideWindow (SDLFrame* sdl);

uint8_t SDLFrame_PollEvent (SDLFrame* sdl);

#endif