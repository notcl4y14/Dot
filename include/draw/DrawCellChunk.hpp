#ifndef DOT_RENDER_CELLCHUNK_HPP
#define DOT_RENDER_CELLCHUNK_HPP

#include <cells/CellChunk.hpp>
#include <draw/Drawer.hpp>

namespace Dot
{
	class DrawCellChunk : public Drawer
	{
	private:
	public:
		Dot::CellChunk* cellChunk;

		void Draw ();
	};
}

#endif