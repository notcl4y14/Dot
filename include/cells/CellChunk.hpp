#ifndef DOT_CELLS_CELLCHUNK_HPP
#define DOT_CELLS_CELLCHUNK_HPP

#include <cells/Cell.hpp>
#include <defines.hpp>

namespace Dot::cells
{
	class CellChunk
	{
	private:
		Dot::cells::Cell* cells;
		uint32_t area;
		uint32_t width;
		uint32_t height;

	public:
		CellChunk ();
		CellChunk (uint32_t width, uint32_t height);
		~CellChunk ();

		void Init (uint32_t width, uint32_t height);

		Dot::cells::Cell* GetCell (uint32_t index);
		Dot::cells::Cell* GetCell (uint32_t x, uint32_t y);

		void SetCell (uint32_t index, Cell cell);
		void SetCell (uint32_t x, uint32_t y, Cell cell);
	};
}

#endif