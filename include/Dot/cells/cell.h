#ifndef DOT_CELL_H
#define DOT_CELL_H

#include <stdint.h>

typedef enum CellID : uint8_t
{
	Air = 0,
	Sand,
} CellID;

typedef struct Cell
{
	CellID id;
	uint8_t color[4];
} Cell;

typedef struct CellStats
{
	CellID id;
	uint8_t* colors;
	uint32_t colors_c;

	uint8_t is_empty;
	uint8_t is_solid;
	uint8_t is_powder;
	uint8_t is_fluid;
} CellStats;

#endif