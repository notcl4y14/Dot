#ifndef DOT_CELLCHUNK_H
#define DOT_CELLCHUNK_H

#include <Dot/cells/cell.h>
#include <Dot/sdl_frame.h>

#include <stdint.h>

typedef struct CellChunk
{
	Cell* cells;
	uint32_t width;
	uint32_t height;
	uint32_t area;
} CellChunk;

void CellChunk_Init (CellChunk* chunk, uint32_t width, uint32_t height);
void CellChunk_Free (CellChunk* chunk);

void CellChunk_Update (CellChunk* chunk);
void CellChunk_Render (CellChunk* chunk, SDLFrame* sdl, uint32_t scale);

Cell* CellChunk_GetCell (CellChunk* chunk, uint32_t x, uint32_t y);
void CellChunk_SetCell (CellChunk* chunk, uint32_t x, uint32_t y, Cell cell);

void CellChunk_SwapCells (CellChunk* chunk, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);

#endif