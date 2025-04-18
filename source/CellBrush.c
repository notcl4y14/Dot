#include <Dot/CellBrush.h>
#include <Dot/Cell.h>
#include <Dot/CellChunk.h>

#include <stdint.h>

void CellBrush_Rectangle (CellChunk* cell_chunk, uint32_t x, uint32_t y, uint32_t w, uint32_t h, Cell cell)
{
	for (uint32_t _x = x; _x < x + w; _x++)
	{
		for (uint32_t _y = y; _y < y + h; _y++)
		{
			CellChunk_SetCell(cell_chunk, _x, _y, cell);
		}
	}
}