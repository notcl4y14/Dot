#ifndef DOT_CELLBRUSH_H
#define DOT_CELLBRUSH_H

#include <Dot/Cell.h>
#include <Dot/CellChunk.h>

#include <stdint.h>

void CellBrush_Rectangle (CellChunk* cell_chunk, uint32_t x, uint32_t y, uint32_t w, uint32_t h, Cell cell);

#endif