#ifndef DOT_DOTAPP_H
#define DOT_DOTAPP_H

#include <Dot/CellChunk.h>
#include <Dot/CellOptions.h>
#include <Dot/LoopManager.h>
#include <Dot/ResManager.h>

#include <stdint.h>
#include <stdbool.h>

struct         DotApp;
typedef struct DotApp DotApp;

struct DotApp
{
	bool is_running;

	CellChunk   cell_chunk;
	ResManager  cell_opt_manager;
	LoopManager loop;
};

void DotApp_Create (DotApp* dot);
void DotApp_Delete (DotApp* dot);

void         DotApp_LoadCellOptions (DotApp* dot, uint32_t id, CellOptions cell_opt);
CellOptions* DotApp_GetCellOptions (DotApp* dot, uint32_t id);

#endif