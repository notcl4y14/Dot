#include <Dot/dot_frame.h>
#include <Dot/cells/cell_chunk.h>
#include <Dot/manager.h>
#include <Dot/runner.h>
#include <Dot/sdl_frame.h>

#include <stdlib.h>

DotFrame* DotFrame_Create ()
{
	DotFrame* dot = malloc(sizeof(DotFrame));

	dot->cell_chunk = calloc(sizeof(CellChunk), 1);
	dot->cell_manager = calloc(sizeof(Manager), 1);
	dot->runner = calloc(sizeof(Runner), 1);
	dot->running = 0;
	dot->tick_count = 0;

	return dot;
}

void      DotFrame_Delete (DotFrame* dot)
{
	uint32_t loop_idx, loop_end;

	CellChunk_Free(dot->cell_chunk);
	free(dot->cell_chunk);
	dot->cell_chunk = NULL;

	loop_idx = -1;
	loop_end = dot->cell_manager->size / dot->cell_manager->stride;

	while (++loop_idx < loop_end)
	{
		CellStats_Free(Manager_GetUnitPtr(dot->cell_manager, loop_idx));
	}

	Manager_Free(dot->cell_manager);
	free(dot->cell_manager);
	dot->cell_manager = NULL;

	free(dot->runner);
	dot->runner = NULL;
}

// 

uint8_t DotFrame_IsRunning (DotFrame* dot)
{
	return dot->running;
}

// 

void DotFrame_Start (DotFrame* dot)
{
	dot->running = 1;
	Runner_Start(dot->runner);
}

void DotFrame_Stop (DotFrame* dot)
{
	dot->running = 0;
}

// 

void DotFrame_Tick (DotFrame* dot)
{
	dot->tick_count++;
	Runner_Next(dot->runner);
}