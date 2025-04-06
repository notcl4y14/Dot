#ifndef DOT_CELLS_CELL_HPP
#define DOT_CELLS_CELL_HPP

#include <defines.hpp>

namespace Dot::cells
{
	class Cell
	{
	private:
	public:
		Cell ();
		Cell (uint32_t id);
		Cell (uint32_t id, dcolori_t color);

		uint32_t id;
		dcolori_t color;
	};
}

#endif