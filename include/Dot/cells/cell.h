#ifndef DOT_CELL_H
#define DOT_CELL_H

#include <stdint.h>

enum   CellID;
struct Cell;
struct CellStats;
struct CellChunk;

typedef void (*CellMethod) (struct CellChunk*, struct Cell* cell, uint32_t x, uint32_t y);

typedef enum CellID
{
	CellID_Air = 0,
	CellID_Sand,
	CellID_Stone
} CellID;

typedef struct Cell
{
	uint8_t id;
	uint32_t color;
	uint8_t fall;
} Cell;

typedef struct CellStats
{
	uint8_t id;
	uint32_t* colors_v;
	uint32_t colors_c;

	uint8_t is_update;
	uint8_t is_render;

	uint8_t is_empty;
	uint8_t is_solid;
	uint8_t is_powder;
	uint8_t is_fluid;

	CellMethod method;
} CellStats;

Cell Cell_CreateFromStats (CellStats* cell_stats);

void CellStats_Free (CellStats* cell_stats);

#endif