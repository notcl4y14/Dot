#include <Dot/CellChunk.h>
#include <Dot/Cell.h>
#include <Dot/Main.h>

#include <SFML/Graphics.h>

#include <stdlib.h>
#include <stdint.h>

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
	for (int32_t x = 0; x < cell_chunk->width; x++)
	{
		for (int32_t y = cell_chunk->height - 1; y >= 0; y--)
		{
			Cell* const cell = CellChunk_GetCell(cell_chunk, x, y);
			CellOptions* const cell_opt = DotApp_GetCellOptions(Dot_DotApp, cell->id);

			if (cell_opt->should_update == false)
			{
				continue;
			}

			cell_opt->update_method(cell_chunk, cell, x, y);
		}
	}
}

void CellChunk_Render (CellChunk* cell_chunk)
{
	sfRectangleShape* sfml_rectangle = sfRectangleShape_create();

	for (int32_t i = 0; i < cell_chunk->area; i++)
	{
		Cell* const cell = &cell_chunk->cells[i];

		if (cell->id == 0)
		{
			continue;
		}

		if (cell->id == 1)
		{
			sfRectangleShape_setFillColor(sfml_rectangle, sfYellow);
		}

		sfRectangleShape_setPosition(sfml_rectangle, (sfVector2f) {i % cell_chunk->width * 4, i / cell_chunk->width * 4});
		sfRectangleShape_setSize(sfml_rectangle, (sfVector2f) {4, 4});

		sfRenderWindow_drawRectangleShape(Dot_SFMLApp->window, sfml_rectangle, NULL);
	}

	sfRectangleShape_destroy(sfml_rectangle);
}