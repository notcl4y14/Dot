#include <Dot/cells/cell.h>

#include <SDL3/SDL.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void Cell_Init (Cell* cell, uint8_t id, uint32_t color, bool fall)
{
	cell->id = id;
	cell->color = color;
	cell->fall = fall;
}

void Cell_Free (Cell* cell)
{
	cell->id = 0;
	cell->color = 0x00000000;
	cell->fall = false;
}

Cell Cell_CreateFromStats (CellStats* cell_stats)
{
	Cell cell;

	srand(SDL_GetTicks());
	uint32_t r = rand();

	cell.id = cell_stats->id;
	cell.color = cell_stats->is_render ? cell_stats->colors_v[r % cell_stats->colors_c] : 0;
	cell.fall = cell_stats->is_powder || cell_stats->is_fluid;

	return cell;
}

void Cell_InitFromStats (Cell* cell, CellStats* cell_stats)
{
	srand(SDL_GetTicks());
	uint32_t r = rand();

	cell->id = cell_stats->id;
	cell->color = cell_stats->is_render ? cell_stats->colors_v[r % cell_stats->colors_c] : 0;
	cell->fall = cell_stats->is_powder || cell_stats->is_fluid;
}

void CellStats_Free (CellStats* cell_stats)
{
	if (cell_stats->colors_v != NULL)
	{
		free(cell_stats->colors_v);
	}

	cell_stats->id = 0;
	cell_stats->colors_v = NULL;
	cell_stats->colors_c = 0;

	cell_stats->is_update = false;
	cell_stats->is_render = false;

	cell_stats->is_empty = false;
	cell_stats->is_solid = false;
	cell_stats->is_powder = false;
	cell_stats->is_fluid = false;

	cell_stats->method = NULL;
}