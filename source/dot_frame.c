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