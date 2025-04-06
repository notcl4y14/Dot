#include <cells/CellChunk.hpp>

Dot::CellChunk::CellChunk () {}

Dot::CellChunk::CellChunk (uint32_t width, uint32_t height)
{
	Init(width, height);
}

Dot::CellChunk::~CellChunk ()
{
	delete[] cells;
}

void Dot::CellChunk::Init (uint32_t width, uint32_t height)
{
	this->width = width;
	this->height = height;
	this->area = width * height;
	this->cells = new Dot::Cell[area];
}

uint32_t Dot::CellChunk::GetArea ()
{
	return area;
}

uint32_t Dot::CellChunk::GetWidth ()
{
	return width;
}

uint32_t Dot::CellChunk::GetHeight ()
{
	return height;
}

Dot::Cell* Dot::CellChunk::GetCell (uint32_t index)
{
	return &cells[index];
}

Dot::Cell* Dot::CellChunk::GetCell (uint32_t x, uint32_t y)
{
	return &cells[x + y * width];
}

void Dot::CellChunk::SetCell (uint32_t index, Dot::Cell cell)
{
	cells[index] = cell;
}

void Dot::CellChunk::SetCell (uint32_t x, uint32_t y, Dot::Cell cell)
{
	cells[x + y * width] = cell;
}