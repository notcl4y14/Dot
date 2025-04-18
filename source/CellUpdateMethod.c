#include <Dot/CellUpdateMethod.h>
#include <Dot/Cell.h>
#include <Dot/CellChunk.h>
#include <Dot/Main.h>

#include <stdint.h>

uint32_t _CellUpdateMethod_Powder (CellChunk* cell_chunk, Cell* cell, uint32_t x, uint32_t y)
{
	if (y == cell_chunk->height - 1)
	{
		return 0;
	}

	Cell* const down_cell = CellChunk_GetCell(cell_chunk, x, y + 1);
	CellOptions* const down_cell_opt = DotApp_GetCellOptions(Dot_DotApp, down_cell->id);

	if (down_cell_opt->is_empty == true)
	{
		Cell air = {0};
		CellChunk_SetCell(cell_chunk, x, y + 1, *cell);
		CellChunk_SetCell(cell_chunk, x, y, air);
		return 0;
	}

	Cell* const left_cell = CellChunk_GetCell(cell_chunk, x - 1, y + 1);
	Cell* const right_cell = CellChunk_GetCell(cell_chunk, x + 1, y + 1);
	CellOptions* const left_cell_opt = DotApp_GetCellOptions(Dot_DotApp, left_cell->id);
	CellOptions* const right_cell_opt = DotApp_GetCellOptions(Dot_DotApp, right_cell->id);

	if (x > 0 && left_cell_opt->is_empty == true)
	{
		Cell air = {0};
		CellChunk_SetCell(cell_chunk, x - 1, y + 1, *cell);
		CellChunk_SetCell(cell_chunk, x, y, air);
		return 0;
	}

	if (x < cell_chunk->width - 1 && right_cell_opt->is_empty == true)
	{
		Cell air = {0};
		CellChunk_SetCell(cell_chunk, x + 1, y + 1, *cell);
		CellChunk_SetCell(cell_chunk, x, y, air);
		return 0;
	}
}