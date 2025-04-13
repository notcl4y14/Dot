#include <Dot/cells/cell.h>

#include <SDL3/SDL.h>

#include <time.h>
#include <stdlib.h>
#include <stdint.h>

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

void CellStats_Free (CellStats* cell_stats)
{
	if (cell_stats->colors_v != NULL)
	{
		free(cell_stats->colors_v);
		cell_stats->colors_v = NULL;
	}
}