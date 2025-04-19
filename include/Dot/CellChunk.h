#ifndef DOT_CELLCHUNK_H
#define DOT_CELLCHUNK_H

#include <Dot/Cell.h>

#include <stdint.h>

struct         CellChunk;
typedef struct CellChunk CellChunk;

struct CellChunk
{
	Cell* cells;
	int32_t width;
	int32_t height;
	int32_t area;
};

void CellChunk_Create (CellChunk* cell_chunk);
void CellChunk_Delete (CellChunk* cell_chunk);

void CellChunk_Init (CellChunk* cell_chunk, int32_t width, int32_t height);
void CellChunk_Clone (CellChunk* cell_chunk_to, CellChunk* cell_chunk_from);
void CellChunk_CopyCells (CellChunk* cell_chunk_to, CellChunk* cell_chunk_from);

Cell* CellChunk_GetCell (CellChunk* cell_chunk, int32_t x, int32_t y);
void  CellChunk_SetCell (CellChunk* cell_chunk, int32_t x, int32_t y, Cell cell);

void CellChunk_Update (CellChunk* cell_chunk);
void CellChunk_Render (CellChunk* cell_chunk);

#endif