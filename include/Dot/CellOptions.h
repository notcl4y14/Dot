#ifndef DOT_CELLOPTIONS_H
#define DOT_CELLOPTIONS_H

#include <Dot/Cell.h>
#include <Dot/CellChunk.h>

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t (*CellUpdateMethod) (CellChunk*, Cell*, uint32_t x, uint32_t y);

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
	CellUpdateMethod update_method;
};

void CellOptions_Create (CellOptions* cell_opt);
void CellOptions_Delete (CellOptions* cell_opt);

#endif