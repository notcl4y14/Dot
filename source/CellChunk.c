#include <Dot/CellChunk.h>
#include <Dot/Cell.h>
#include <Dot/Main.h>

#include <SFML/Graphics.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void CellChunk_Create (CellChunk* cell_chunk)
{
	cell_chunk->cells = NULL;
	cell_chunk->width = 0;
	cell_chunk->height = 0;
	cell_chunk->area = 0;
}

void CellChunk_Delete (CellChunk* cell_chunk)
{
	free(cell_chunk->cells);

	cell_chunk->cells = NULL;
	cell_chunk->width = 0;
	cell_chunk->height = 0;
	cell_chunk->area = 0;
}

void CellChunk_Init (CellChunk* cell_chunk, int32_t width, int32_t height)
{
	int32_t const area = width * height;
	cell_chunk->cells = calloc(area, sizeof (Cell));
	cell_chunk->width = width;
	cell_chunk->height = height;
	cell_chunk->area = area;
}

void CellChunk_Clone (CellChunk* cell_chunk_to, CellChunk* cell_chunk_from)
{
	int32_t const size = cell_chunk_from->area * sizeof (Cell);
	*cell_chunk_to = *cell_chunk_from;
	cell_chunk_to->cells = malloc(size);
	memcpy(cell_chunk_to->cells, cell_chunk_from->cells, size);
}

void CellChunk_CopyCells (CellChunk* cell_chunk_to, CellChunk* cell_chunk_from)
{
	int32_t const size = cell_chunk_from->area * sizeof (Cell);
	memcpy(cell_chunk_to->cells, cell_chunk_from->cells, size);
}

inline Cell* CellChunk_GetCell (CellChunk* cell_chunk, int32_t x, int32_t y)
{
	return &(cell_chunk->cells[x + y * cell_chunk->width]);
}

inline void CellChunk_SetCell (CellChunk* cell_chunk, int32_t x, int32_t y, Cell cell)
{
	cell_chunk->cells[x + y * cell_chunk->width] = cell;
}

void CellChunk_Update (CellChunk* cell_chunk)
{
	uint32_t const cc_width = cell_chunk->width;
	uint32_t const cc_height = cell_chunk->height;

	// This kind of approach seems bad, unless the chunk is small...
	// ...and unless there are a few chunks to be updated.
	CellChunk new_cell_chunk = *cell_chunk;
	CellChunk_Clone(&(new_cell_chunk), cell_chunk);

	CellChunk* const front_cell_chunk = cell_chunk;
	CellChunk* const back_cell_chunk = &(new_cell_chunk);

	for (int32_t x = 0; x < cc_width; x++)
	{
		for (int32_t y = cc_height - 1; y >= 0; y--)
		{
			Cell* const cell = CellChunk_GetCell(front_cell_chunk, x, y);
			CellOptions* const cell_opt =
				DotApp_GetCellOptions(Dot_DotApp, cell->id);

			if (cell_opt->should_update == false)
			{
				continue;
			}

			cell_opt->update_method(front_cell_chunk, back_cell_chunk, cell, x, y);
		}
	}

	CellChunk_CopyCells(front_cell_chunk, back_cell_chunk);
	CellChunk_Delete(back_cell_chunk);
}

void CellChunk_Render (CellChunk* cell_chunk)
{
	uint8_t canvas[cell_chunk->area * 4];
	memset((uint8_t*)&canvas, 0, cell_chunk->area * 4);

	for (int32_t i = 0; i < cell_chunk->area; i++)
	{
		Cell* const cell = &cell_chunk->cells[i];

		if (cell->id == 0)
		{
			continue;
		}

		if (cell->id == 1)
		{
			canvas[i * 4] = 255;
			canvas[i * 4 + 1] = 255;
			canvas[i * 4 + 2] = 0;
			canvas[i * 4 + 3] = 255;
		}
	}

	sfIntRect rect = {0, 0, cell_chunk->width, cell_chunk->height};
	sfImage* image = sfImage_createFromPixels(cell_chunk->width, cell_chunk->height, (uint8_t*)&canvas);
	sfTexture* texture = sfTexture_createFromImage(image, &rect);
	sfSprite* sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, false);
	sfSprite_setScale(sprite, (sfVector2f) {4, 4});

	sfRenderWindow_drawSprite(Dot_SFMLApp->window, sprite, NULL);

	sfImage_destroy(image);
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}