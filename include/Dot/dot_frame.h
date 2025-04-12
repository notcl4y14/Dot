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

#endif