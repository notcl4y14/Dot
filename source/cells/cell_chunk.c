#include <Dot/cells/cell_chunk.h>
#include <Dot/cells/cell.h>
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
}

// 

void CellChunk_Update (CellChunk* chunk)
{
	// x, y
	int32_t loop1_idx, loop2_idx;
	int32_t loop1_begin, loop1_end;
	int32_t loop2_begin, loop2_end;

	loop1_begin = -1;
	loop2_begin = chunk->height;

	loop1_end = chunk->width;
	loop2_end = 0;

	loop1_idx = loop1_begin;
	loop2_idx = loop2_begin;

	while (++loop1_idx < loop1_end)
	{
		while (--loop2_idx >= loop2_end)
		{
			// printf("(%d; %d)\t", loop1_idx, loop2_idx);
			Cell* cell = CellChunk_GetCell(chunk, loop1_idx, loop2_idx);

			if (cell->id == 0)
			{
				continue;
			}

			// TODO: Make a new storage for cell functions
			if (loop2_idx == chunk->height - 1)
			{
				continue;
			}

			Cell* cell_bottom = CellChunk_GetCell(chunk, loop1_idx, loop2_idx + 1);

			if (cell_bottom->id == 0)
			{
				CellChunk_SwapCells(chunk, loop1_idx, loop2_idx, loop1_idx, loop2_idx + 1);
			}
		}

		loop2_idx = loop2_begin;
	}
}

void CellChunk_Render (CellChunk* cell_chunk, SDLFrame* sdl, uint32_t scale)
{
	SDL_Renderer* renderer = sdl->renderer;
	SDL_FRect frect;
	Cell cell;

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

		if (cell.id == 0)
		{
			continue;
		}

		frect.x = (i % cell_chunk->width) * scale;
		frect.y = (i / cell_chunk->width) * scale;
		frect.w = scale;
		frect.h = scale;

		SDL_SetRenderDrawColor(renderer, cell.color[0], cell.color[1], cell.color[2], cell.color[3]);
		SDL_RenderFillRect(renderer, &frect);
	}
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