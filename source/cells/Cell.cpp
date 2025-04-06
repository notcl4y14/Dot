#include <cells/Cell.hpp>

Dot::Cell::Cell ()
{
	id = 0;
}

Dot::Cell::Cell (uint32_t id)
{
	this->id = id;
}

Dot::Cell::Cell (uint32_t id, dcolori_t color)
{
	this->id = id;
	this->color = color;
}