#include <Dot/CellUpdateMethod.h>
#include <Dot/Cell.h>
#include <Dot/CellChunk.h>
#include <Dot/Main.h>
#include <Dot/System.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

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
	bool const can_go_left =  x > 0                     && left_cell_opt->is_empty == true;
	bool const can_go_right = x < cell_chunk->width - 1 && right_cell_opt->is_empty == true;

	// if (can_go_left == true && can_go_right == true)
	// {
	// 	srand(System_GetTimeMS());
	// 	bool const left = rand() % 2 == 0;
	// 	printf("left: %d\n", left);

	// 	     if (left == true)  goto go_left;
	// 	else if (left == false) goto go_right;
	// }

	srand(System_GetTimeMS());
	bool const left = rand() % 2 == 0;

	if (left == true && can_go_left == true)
	{
		// go_left:
		Cell air = {0};
		CellChunk_SetCell(cell_chunk, x - 1, y + 1, *cell);
		CellChunk_SetCell(cell_chunk, x, y, air);
		return 0;
	}

	if (left == false && can_go_right == true)
	{
		// go_right:
		Cell air = {0};
		CellChunk_SetCell(cell_chunk, x + 1, y + 1, *cell);
		CellChunk_SetCell(cell_chunk, x, y, air);
		return 0;
	}
}