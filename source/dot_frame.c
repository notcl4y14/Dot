#include <Dot/dot_frame.h>
#include <Dot/cells/cell_chunk.h>
#include <Dot/manager.h>
#include <Dot/runner.h>
#include <Dot/sdl_frame.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

DotFrame* DotFrame_Create ()
{
	DotFrame* dot = malloc(sizeof(DotFrame));

	dot->cell_chunk.cells = NULL;
	dot->cell_chunk.width = 0;
	dot->cell_chunk.height = 0;
	dot->cell_chunk.area = 0;

	dot->cell_manager.data = NULL;
	dot->cell_manager.size = 0;
	dot->cell_manager.stride = 0;

	dot->runner.lps_current = 0;
	dot->runner.lps_target = 0;
	dot->runner.lps_counter = 0;
	dot->runner.lps_counter_ntime = 0;
	dot->runner.loop_count = 0;

	dot->is_running = false;
	dot->tick_count = 0;

	return dot;
}

void DotFrame_Delete (DotFrame* dot)
{
	CellChunk* const cell_chunk = &dot->cell_chunk;
	Manager* const cell_manager = &dot->cell_manager;
	Runner* const runner = &dot->runner;

	uint32_t loop_idx, loop_end;

	loop_idx = -1;
	loop_end = cell_manager->size / cell_manager->stride;

	while (++loop_idx < loop_end)
	{
		CellStats* const cell_stats =
			Manager_GetUnitPtr(cell_manager, loop_idx);
		CellStats_Free(cell_stats);
	}

	CellChunk_Free(cell_chunk);
	Manager_Free(cell_manager);
	Runner_Free(runner);

	dot->is_running = false;
	dot->tick_count = 0;
}

// 

inline bool DotFrame_IsRunning (DotFrame* dot)
{
	return dot->is_running;
}

inline uint32_t DotFrame_TickCount (DotFrame* dot)
{
	return dot->tick_count;
}

// 

void DotFrame_Start (DotFrame* dot)
{
	dot->is_running = true;
	Runner_Start(&dot->runner);
}

void DotFrame_Stop (DotFrame* dot)
{
	dot->is_running = false;
	Runner_Stop(&dot->runner);
}

// 

void DotFrame_Tick (DotFrame* dot)
{
	dot->tick_count++;
	Runner_Tick(&dot->runner);
}