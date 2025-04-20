#include <Dot/CellChunkArray.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void read_offset (FILE* file, void* to, uint32_t size, uint32_t offset)
{
	// uint32_t i = -1;
	// char* buffer = malloc(size);

	// for (int32_t j = 0; j < offset; j++)
	// {
	// 	fgetc(file);
	// }

	// while (++i < size)
	// {
	// 	buffer[i] = fgetc(file);
	// }

	// memcpy(to, buffer, size);
	// free(buffer);
	fseek(file, offset, SEEK_SET);
	fread(to, size, 1, file);
	// fseek(file, 0, SEEK_SET);
}

void CellChunkArray_Create (CellChunkArray* cc_arr)
{
	cc_arr->cc_kx = NULL;
	cc_arr->cc_ky = NULL;
	cc_arr->cc_v = NULL;

	cc_arr->chunk_width = 0;
	cc_arr->chunk_height = 0;
	cc_arr->chunk_load_range_h = 0;
	cc_arr->chunk_load_range_v = 0;

	cc_arr->chunk_amount = 0;

	cc_arr->update_file = NULL;
}

void CellChunkArray_Delete (CellChunkArray* cc_arr)
{
	for (int32_t i = 0; i < cc_arr->chunk_amount; i++)
	{
		CellChunk_Delete(&(cc_arr->cc_v[i]));
	}

	free(cc_arr->cc_kx);
	free(cc_arr->cc_ky);
	free(cc_arr->cc_v);

	cc_arr->cc_kx = NULL;
	cc_arr->cc_ky = NULL;
	cc_arr->cc_v = NULL;

	cc_arr->chunk_width = 0;
	cc_arr->chunk_height = 0;
	cc_arr->chunk_load_range_h = 0;
	cc_arr->chunk_load_range_v = 0;

	cc_arr->chunk_amount = 0;

	cc_arr->update_file = NULL;
}

void CellChunkArray_LoadFromFile (CellChunkArray* cc_arr, FILE* file)
{
	int32_t chunk_width, chunk_height;

	// fread(chunk_width, sizeof(int32_t), 1, file);
	// fread(chunk_width, sizeof(int32_t), 1, file);
	// fread(&chunk_width, sizeof(int32_t), 0, file);
	// fread(&chunk_height, sizeof(int32_t), sizeof(int32_t) * 1, file);
	// pread(file, &chunk_arr_width, sizeof(int32_t), sizeof(int32_t) * 2);
	// pread(file, &chunk_arr_height, sizeof(int32_t), sizeof(int32_t) * 3);
	read_offset(file, &chunk_width, sizeof(int32_t), 0);
	read_offset(file, &chunk_height, sizeof(int32_t), 4);

	printf("%d, %d\n", chunk_width, chunk_height);

	cc_arr->chunk_width = chunk_width;
	cc_arr->chunk_height = chunk_height;
	// cc_arr->chunk_arr_width = chunk_arr_width;
	// cc_arr->chunk_arr_height = chunk_arr_height;
	cc_arr->chunk_amount =
		  (cc_arr->chunk_load_range_h * 2) * (cc_arr->chunk_load_range_v * 2)
		+ (cc_arr->chunk_load_range_h + cc_arr->chunk_load_range_v);

	cc_arr->cc_kx = calloc(cc_arr->chunk_amount, sizeof(int32_t));
	cc_arr->cc_ky = calloc(cc_arr->chunk_amount, sizeof(int32_t));
	cc_arr->cc_v = calloc(cc_arr->chunk_amount, sizeof(CellChunk));

	cc_arr->update_file = file;
}

void CellChunkArray_Load (CellChunkArray* cc_arr, int32_t x, int32_t y)
{
	int32_t left = -cc_arr->chunk_load_range_h + x;
	int32_t right = cc_arr->chunk_load_range_h + x;
	int32_t top = -cc_arr->chunk_load_range_v + y;
	int32_t bottom = cc_arr->chunk_load_range_v + y;

	int32_t index = 0;

	for (int32_t _x = left; _x < right; _x++)
	{
		for (int32_t _y = top; _y < bottom; _y++)
		{
			CellChunk cell_chunk;
			CellChunkArray_ReadChunk(cc_arr, &cell_chunk, _x, _y);

			cc_arr->cc_kx[index] = _x;
			cc_arr->cc_ky[index] = _y;
			cc_arr->cc_v[index] = cell_chunk;

			index++;
		}
	}
}

void CellChunkArray_Reload (CellChunkArray* cc_arr, int32_t x, int32_t y)
{
	for (int32_t i = 0; i < cc_arr->chunk_amount; i++)
	{
		CellChunk_Delete(&(cc_arr->cc_v[i]));
	}

	CellChunkArray_Load(cc_arr, x, y);
}

int32_t CellChunkArray_GetChunkFileOffset (CellChunkArray* cc_arr, int32_t x, int32_t y)
{
	// TODO: Change this to loop until found something or EOF
	for (int32_t i = 0; i < 50; i++)
	{
		int32_t _x, _y;
		int32_t const address = 8 + (i * ((cc_arr->chunk_width * cc_arr->chunk_height) * 4 + 8));
		// pread(cc_arr->update_file, &_x, sizeof(int32_t), address);
		// pread(cc_arr->update_file, &_y, sizeof(int32_t), address + 4);
		read_offset(cc_arr->update_file, &_x, sizeof(int32_t), address);
		read_offset(cc_arr->update_file, &_y, sizeof(int32_t), address + 4);

		// printf("%d, %d, %d\n", address, _x, _y);

		if (_x == x && _y == y)
		{
			return address;
		}
	}

	return 0;
}
void CellChunkArray_ReadChunk (CellChunkArray* cc_arr, CellChunk* cell_chunk, int32_t x, int32_t y)
{
	int32_t offset = CellChunkArray_GetChunkFileOffset(cc_arr, x, y);
	if (offset == 0)
	{
		printf("Cell Chunk at (%d;%d) not found\n", x, y);
		exit(1);
	}
	cell_chunk->width = cc_arr->chunk_width;
	cell_chunk->height = cc_arr->chunk_height;
	cell_chunk->area = cc_arr->chunk_width * cc_arr->chunk_height;
	cell_chunk->cells = malloc(cell_chunk->area * sizeof(Cell));
	// pread(cc_arr->update_file, cell_chunk->cells, sizeof(int8_t) * cell_chunk->area, offset);
	read_offset(cc_arr->update_file, cell_chunk->cells, sizeof(int8_t) * cell_chunk->area, offset);
}
CellChunk* CellChunkArray_GetLoadedChunk (CellChunkArray* cc_arr, int32_t x, int32_t y)
{
	for (int32_t i = 0; i < cc_arr->chunk_amount; i++)
	{
		if (cc_arr->cc_kx[i] == x && cc_arr->cc_ky[i] == y)
		{
			return &(cc_arr->cc_v[i]);
		}
	}

	return NULL;
}