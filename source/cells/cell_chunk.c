#include <Dot/cells/cell_chunk.h>
#include <Dot/cells/cell.h>
#include <Dot/main.h>
#include <Dot/sdl_frame.h>

#include <SDL3/SDL.h>

#include <stdio.h>
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
	chunk->width = 0;
	chunk->height = 0;
	chunk->area = 0;
}

// 

void CellChunk_Update (CellChunk* chunk)
{
	// x, y
	int32_t loop_x_idx, loop_y_idx;
	int32_t loop_x_begin, loop_y_begin;
	int32_t loop_x_end, loop_y_end;

	// X iterator starts from 0
	// Y iterator starts from the chunk height value
	loop_x_begin = -1;
	loop_y_begin = chunk->height;

	// X iterator ends on the chunk width value
	// Y iterator ends on 0
	loop_x_end = chunk->width;
	loop_y_end = 0;

	loop_x_idx = loop_x_begin;
	loop_y_idx = loop_y_begin;

	while (++loop_x_idx < loop_x_end)
	{
		while (--loop_y_idx >= loop_y_end)
		{
			Cell* const cell =
				CellChunk_GetCell(chunk, loop_x_idx, loop_y_idx);
			const CellStats* cell_stats =
				Manager_GetUnitPtr(&_DotFrame->cell_manager, cell->id);

			if (cell_stats->is_update == false)
			{
				continue;
			}

			cell_stats->method(chunk, cell, loop_x_idx, loop_y_idx);
		}

		loop_y_idx = loop_y_begin;
	}
}

void CellChunk_Render (CellChunk* cell_chunk, uint32_t scale)
{
	SDL_Renderer* renderer = _SDLFrame->renderer;
	SDL_FRect frect;
	Cell cell;
	CellStats* cell_stats;
	uint8_t color[4];

	// Render CellChunk borders
	frect.x = 0;
	frect.y = 0;
	frect.w = cell_chunk->width * scale;
	frect.h = cell_chunk->height * scale;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderRect(renderer, &frect);

	// Render CellChunk cells
	for (uint32_t i = 0; i < cell_chunk->area; i++)
	{
		cell = cell_chunk->cells[i];
		cell_stats = Manager_GetUnitPtr(&_DotFrame->cell_manager, cell.id);

		if (cell_stats->is_render == false)
		{
			continue;
		}

		frect.x = (i % cell_chunk->width) * scale;
		frect.y = (i / cell_chunk->width) * scale;
		frect.w = scale;
		frect.h = scale;

		// color = cell.color;
		// memcpy((&color)[1], (uint8_t*)((&cell.color))[1], sizeof(uint8_t));
		// memcpy((&color)[0], (uint8_t*)((&cell.color))[0], sizeof(uint8_t));
		// memcpy((&color)[2], (uint8_t*)((&cell.color))[2], sizeof(uint8_t));
		// memcpy((&color)[3], (uint8_t*)((&cell.color))[3], sizeof(uint8_t));

		// May not be Different-Endian-Proof
		color[0] = (cell.color >> 24) & 0xFF;
		color[1] = (cell.color >> 16) & 0xFF;
		color[2] = (cell.color >> 8) & 0xFF;
		color[3] = cell.color & 0xFF;

		SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
		SDL_RenderFillRect(renderer, &frect);
	}
}

// 

inline Cell* CellChunk_GetCell (CellChunk* chunk, uint32_t x, uint32_t y)
{
	return &chunk->cells[x + y * chunk->width];
}

inline void CellChunk_SetCell (CellChunk* chunk, uint32_t x, uint32_t y, Cell cell)
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