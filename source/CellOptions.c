#include <Dot/CellOptions.h>

#include <stdint.h>
#include <stdbool.h>

void CellOptions_Create (CellOptions* cell_opt)
{
	cell_opt->id = 0;
	cell_opt->should_update = false;
	cell_opt->should_render = false;
	cell_opt->is_empty = false;
	cell_opt->is_solid = false;
	cell_opt->is_powder = false;
	cell_opt->is_fluid = false;
}

void CellOptions_Delete (CellOptions* cell_opt)
{
	cell_opt->id = 0;
	cell_opt->should_update = false;
	cell_opt->should_render = false;
	cell_opt->is_empty = false;
	cell_opt->is_solid = false;
	cell_opt->is_powder = false;
	cell_opt->is_fluid = false;
}