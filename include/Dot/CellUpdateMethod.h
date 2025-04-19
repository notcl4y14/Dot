#ifndef DOT_CELLUPDATEMETHOD_H
#define DOT_CELLUPDATEMETHOD_H

#include <Dot/Cell.h>
#include <Dot/CellChunk.h>

#include <stdint.h>

uint32_t _CellUpdateMethod_Powder (CellChunk* cc_front, CellChunk* cc_back, Cell* cell, uint32_t x, uint32_t y);

#endif