#ifndef DOT_CELL_H
#define DOT_CELL_H

#include <stdint.h>
#include <stdbool.h>

struct Cell;
struct CellState;
struct CellStats;
struct CellChunk;

typedef uint8_t (*CellMethod) (struct CellChunk*, struct Cell* cell, uint32_t x, uint32_t y);

typedef enum CellID
{
	CellID_Air = 0,
	CellID_Sand,
	CellID_Stone
} CellID;

typedef struct CellState
{
	uint32_t alive_counter;
} CellState;

typedef struct Cell
{
	uint8_t id;
	uint32_t color;
	bool fall;

	CellState state;
} Cell;

typedef struct CellStats
{
	uint8_t id;
	uint32_t* colors_v;
	uint32_t colors_c;

	bool is_update;
	bool is_render;

	bool is_empty;
	bool is_solid;
	bool is_powder;
	bool is_fluid;

	CellMethod method;
} CellStats;

void Cell_Init (Cell* cell, uint8_t id, uint32_t color, bool fall);
void Cell_Free (Cell* cell);

Cell Cell_CreateFromStats (CellStats* cell_stats);
void Cell_InitFromStats (Cell* cell, CellStats* cell_stats);

void CellStats_Init (CellStats* cell_stats);
void CellStats_Free (CellStats* cell_stats);

#endif