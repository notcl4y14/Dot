#ifndef DOT_DOTFRAME_H
#define DOT_DOTFRAME_H

#include <Dot/cells/cell_chunk.h>
#include <Dot/manager.h>
#include <Dot/runner.h>
#include <Dot/sdl_frame.h>

#include <stdint.h>
#include <stdbool.h>

typedef struct DotFrame
{
	// Components
	CellChunk cell_chunk;   // TODO: Implement this in another struct, perhaps.
	Manager   cell_manager;
	Runner    runner;       // TODO: uhhh Idk, maybe rename the struct.

	// Application State
	bool     is_running;
	uint32_t tick_count;
} DotFrame;

DotFrame* DotFrame_Create ();
void      DotFrame_Delete (DotFrame* dot);

bool DotFrame_IsRunning (DotFrame* dot);
uint32_t DotFrame_TickCount (DotFrame* dot);

void DotFrame_Start (DotFrame* dot);
void DotFrame_Stop (DotFrame* dot);

void DotFrame_Tick (DotFrame* dot);

#endif