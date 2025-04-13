#ifndef DOT_DOTFRAME_H
#define DOT_DOTFRAME_H

#include <Dot/cells/cell_chunk.h>
#include <Dot/sdl_frame.h>
#include <Dot/runner.h>

typedef struct DotFrame
{
	CellChunk* cell_chunk;

	Runner* runner;

	uint8_t running;
	uint32_t tick_count;
} DotFrame;

DotFrame* DotFrame_Create ();
void      DotFrame_Delete (DotFrame* dot);

uint8_t DotFrame_IsRunning (DotFrame* dot);

void DotFrame_Start (DotFrame* dot);
void DotFrame_Stop (DotFrame* dot);

void DotFrame_Tick (DotFrame* dot);

#endif