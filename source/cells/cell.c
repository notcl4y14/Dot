#include <Dot/cells/cell.h>

#include <stdlib.h>
#include <stdint.h>

Cell Cell_CreateFromStats (CellStats* cell_stats)
{
	Cell cell;

	cell.id = cell_stats->id;
	cell.color = cell_stats->is_render ? cell_stats->colors_v[0] : 0;
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