#ifndef DOT_CELLS_CELLCHUNK_HPP
#define DOT_CELLS_CELLCHUNK_HPP

#include <cells/Cell.hpp>
#include <defines.hpp>

namespace Dot
{
	class CellChunk
	{
	private:
		Dot::Cell* cells;
		uint32_t area;
		uint32_t width;
		uint32_t height;

	public:
		CellChunk ();
		CellChunk (uint32_t width, uint32_t height);
		~CellChunk ();

		void Init (uint32_t width, uint32_t height);

		uint32_t GetArea ();
		uint32_t GetWidth ();
		uint32_t GetHeight ();

		Dot::Cell* GetCell (uint32_t index);
		Dot::Cell* GetCell (uint32_t x, uint32_t y);

		void SetCell (uint32_t index, Dot::Cell cell);
		void SetCell (uint32_t x, uint32_t y, Dot::Cell cell);
	};
}

#endif