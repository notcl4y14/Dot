#ifndef DOT_DOTFRAME_H
#define DOT_DOTFRAME_H

#include <Dot/sdl_frame.h>

typedef struct DotFrame
{
	SDLFrame* sdl_frame;

	uint8_t running;
} DotFrame;

DotFrame* DotFrame_Create ();
void      DotFrame_Delete (DotFrame* dot);

SDLFrame* DotFrame_GetSDLFrame (DotFrame* dot);
uint8_t DotFrame_IsRunning (DotFrame* dot);

void DotFrame_Start (DotFrame* dot);
void DotFrame_Stop (DotFrame* dot);

#endif