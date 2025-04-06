#ifndef DOT_RENDER_CELLCHUNK_HPP
#define DOT_RENDER_CELLCHUNK_HPP

#include <cells/CellChunk.hpp>
#include <render/Renderer.hpp>

namespace Dot
{
	class RenderCellChunk : public Renderer
	{
	private:
	public:
		Dot::CellChunk* cellChunk;

		virtual void Render ();
	};
}

#endif