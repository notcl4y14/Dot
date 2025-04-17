#include <Dot/DotApp.h>
#include <Dot/LoopManager.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void DotApp_Create (DotApp* dot)
{
	dot->is_running = false;

	CellChunk_Create(&dot->cell_chunk);
	LoopManager_Create(&dot->loop);
}

void DotApp_Delete (DotApp* dot)
{
	dot->is_running = false;

	CellChunk_Delete(&dot->cell_chunk);
	LoopManager_Delete(&dot->loop);
}