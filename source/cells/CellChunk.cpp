#include <cells/CellChunk.hpp>

Dot::cells::CellChunk::CellChunk () {}

Dot::cells::CellChunk::CellChunk (uint32_t width, uint32_t height)
{
	Init(width, height);
}

Dot::cells::CellChunk::~CellChunk ()
{
	delete[] cells;
}

void Dot::cells::CellChunk::Init (uint32_t width, uint32_t height)
{
	this->width = width;
	this->height = height;
	this->area = width * height;
	this->cells = new Dot::cells::Cell[area];
}

Dot::cells::Cell* Dot::cells::CellChunk::GetCell (uint32_t index)
{
	return &cells[index];
}

Dot::cells::Cell* Dot::cells::CellChunk::GetCell (uint32_t x, uint32_t y)
{
	return &cells[x + y * width];
}

void Dot::cells::CellChunk::SetCell (uint32_t index, Dot::cells::Cell cell)
{
	cells[index] = cell;
}

void Dot::cells::CellChunk::SetCell (uint32_t x, uint32_t y, Dot::cells::Cell cell)
{
	cells[x + y * width] = cell;
}