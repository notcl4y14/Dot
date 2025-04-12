#include <Dot/dot_frame.h>
#include <Dot/sdl_frame.h>

#include <stdlib.h>

DotFrame* DotFrame_Create ()
{
	DotFrame* dot = malloc(sizeof(DotFrame));

	dot->sdl_frame = SDLFrame_Create();
	dot->running = 0;

	return dot;
}

void      DotFrame_Delete (DotFrame* dot)
{
	SDLFrame_Delete(dot->sdl_frame);
}

// 

SDLFrame* DotFrame_GetSDLFrame (DotFrame* dot)
{
	return dot->sdl_frame;
}

uint8_t DotFrame_IsRunning (DotFrame* dot)
{
	return dot->running;
}

// 

void DotFrame_Start (DotFrame* dot)
{
	dot->running = 1;
}

void DotFrame_Stop (DotFrame* dot)
{
	dot->running = 0;
}