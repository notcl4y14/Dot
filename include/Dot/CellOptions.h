#ifndef DOT_CELLOPTIONS_H
#define DOT_CELLOPTIONS_H

#include <stdint.h>
#include <stdbool.h>

struct         CellOptions;
typedef struct CellOptions CellOptions;

struct CellOptions
{
	uint32_t id;
	bool     should_update;
	bool     should_render;
	bool     is_empty;
	bool     is_solid;
	bool     is_powder;
	bool     is_fluid;
};

void CellOptions_Create (CellOptions* cell_opt);
void CellOptions_Delete (CellOptions* cell_opt);

#endif