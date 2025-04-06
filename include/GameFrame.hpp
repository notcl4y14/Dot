#ifndef DOT_GAMEFRAME_HPP
#define DOT_GAMEFRAME_HPP

#include <SFML/Graphics.hpp>

namespace Dot
{
	class GameFrame
	{
	private:
		sf::RenderWindow window;

	public:
		uint8_t isRunning;
		uint32_t updateCount;

		GameFrame ();

		void CreateWindow (const char* title, uint32_t width, uint32_t height);
		void CloseWindow ();
		sf::RenderWindow* GetWindow ();

		void Start ();
		void Stop ();
	};
}

#endif