#ifndef DOT_GAMEFRAME_HPP
#define DOT_GAMEFRAME_HPP

#include <cells/CellChunk.hpp>
#include <draw/DrawCellChunk.hpp>

#include <SFML/Graphics.hpp>

namespace Dot
{
	class GameFrame
	{
	private:
		sf::RenderWindow window;

		Dot::CellChunk cellChunk;

		Dot::DrawCellChunk rCellChunk;

	public:
		uint8_t isRunning;
		uint32_t updateCount;

		GameFrame ();

		void CreateWindow (const char* title, uint32_t width, uint32_t height);
		void CloseWindow ();
		sf::RenderWindow* GetWindow ();

		void InitCellChunk (uint32_t width, uint32_t height);
		void DeleteCellChunk ();
		Dot::CellChunk* GetCellChunk ();

		sf::RenderTexture rtCellChunk;

		void DrawCellChunk ();

		void Start ();
		void Stop ();
	};
}

#endif