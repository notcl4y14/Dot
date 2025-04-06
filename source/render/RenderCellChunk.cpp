#include <render/RenderCellChunk.hpp>

#include <SFML/Graphics.hpp>

void Dot::RenderCellChunk::Render ()
{
	uint32_t loopIdx = 0;
	uint32_t loopEnd = cellChunk->GetArea();

	uint32_t cellChunkWidth = cellChunk->GetWidth();
	// uint32_t cellChunkHeight = cellChunk->GetHeight();

	sf::RectangleShape rect;

	while (loopIdx != loopEnd)
	{
		Dot::Cell* cell = cellChunk->GetCell(loopIdx);

		if (cell->id == 0)
		{
			loopIdx++;
			continue;
		}

		float x = loopIdx % cellChunkWidth;
		float y = loopIdx / cellChunkWidth;

		rect.setFillColor((sf::Color)cell->color);
		rect.setPosition({x, y});
		rect.setSize({1, 1});

		renderTex->draw(rect);

		loopIdx++;
	}
}