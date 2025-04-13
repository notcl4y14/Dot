#include <Dot/cells/cell_chunk.h>
#include <Dot/cells/cell.h>

#include <stdlib.h>
#include <stdint.h>

void CellChunk_Init (CellChunk* chunk, uint32_t width, uint32_t height)
{
	const uint32_t area = width * height;
	chunk->cells = calloc(area, sizeof(Cell));
	chunk->width = width;
	chunk->height = height;
	chunk->area = area;
}

void CellChunk_Free (CellChunk* chunk)
{
	free(chunk->cells);
	chunk->cells = NULL;
}

// 

Cell* CellChunk_GetCell (CellChunk* chunk, uint32_t x, uint32_t y)
{
	return &chunk->cells[x + y * chunk->width];
}

void CellChunk_SetCell (CellChunk* chunk, uint32_t x, uint32_t y, Cell cell)
{
	chunk->cells[x + y * chunk->width] = cell;
}

// 

void CellChunk_SwapCells (CellChunk* chunk, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	Cell cell1 = *CellChunk_GetCell(chunk, x1, y1);
	Cell cell2 = *CellChunk_GetCell(chunk, x2, y2);

	CellChunk_SetCell(chunk, x1, y1, cell2);
	CellChunk_SetCell(chunk, x2, y2, cell1);
}