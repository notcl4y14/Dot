#ifndef DOT_CELLCHUNKARRAY_H
#define DOT_CELLCHUNKARRAY_H

#include <Dot/CellChunk.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct         CellChunkArray;
typedef struct CellChunkArray CellChunkArray;

struct CellChunkArray
{
	int32_t*   cc_kx;
	int32_t*   cc_ky;
	CellChunk* cc_v;

	int32_t chunk_width;
	int32_t chunk_height;
	int32_t chunk_load_range_h;
	int32_t chunk_load_range_v;

	int32_t chunk_amount;

	FILE* update_file;
};

void CellChunkArray_Create (CellChunkArray* cc_arr);
void CellChunkArray_Delete (CellChunkArray* cc_arr);

void CellChunkArray_LoadFromFile (CellChunkArray* cc_arr, FILE* file);
void CellChunkArray_Reload (CellChunkArray* cc_arr, int32_t x, int32_t y);

int32_t CellChunkArray_GetChunkFileOffset (CellChunkArray* cc_arr, int32_t x, int32_t y);
void CellChunkArray_ReadChunk (CellChunkArray* cc_arr, CellChunk* cell_chunk, int32_t x, int32_t y);
CellChunk* CellChunkArray_GetLoadedChunk (CellChunkArray* cc_arr, int32_t x, int32_t y);

#endif