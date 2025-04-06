#include <cells/Cell.hpp>

Dot::cells::Cell::Cell ()
{
	id = 0;
}

Dot::cells::Cell::Cell (uint32_t id)
{
	this->id = id;
}

Dot::cells::Cell::Cell (uint32_t id, dcolori_t color)
{
	this->id = id;
	this->color = color;
}