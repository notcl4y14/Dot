#include <Dot/DotApp.h>
#include <Dot/CellChunk.h>
#include <Dot/CellOptions.h>
#include <Dot/LoopManager.h>
#include <Dot/ResManager.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void DotApp_Create (DotApp* dot)
{
	dot->is_running = false;

	CellChunk_Create(&dot->cell_chunk);
	ResManager_Create(&dot->cell_opt_manager);
	LoopManager_Create(&dot->loop);
}

void DotApp_Delete (DotApp* dot)
{
	dot->is_running = false;

	CellChunk_Delete(&dot->cell_chunk);
	ResManager_Delete(&dot->cell_opt_manager);
	LoopManager_Delete(&dot->loop);
}

void DotApp_LoadCellOptions (DotApp* dot, uint32_t id, CellOptions cell_opt)
{
	ResManager_LoadUnit(&dot->cell_opt_manager, id, &cell_opt);
}
inline CellOptions* DotApp_GetCellOptions (DotApp* dot, uint32_t id)
{
	return ResManager_GetUnitP(&dot->cell_opt_manager, id);
}