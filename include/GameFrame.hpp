#ifndef DOT_GAMEFRAME_HPP
#define DOT_GAMEFRAME_HPP

#include <SFML/Graphics.hpp>

namespace Dot
{
	class GameFrame
	{
	private:
		sf::RenderWindow window;
		sf::Image canvas_img;
		sf::Texture canvas_tex;
		sf::Sprite canvas_spr;

	public:
		uint8_t isRunning;
		uint32_t updateCount;

		GameFrame ();

		void CreateWindow (const char* title, uint32_t width, uint32_t height);
		void CloseWindow ();
		sf::RenderWindow* GetWindow ();

		sf::Image* GetCanvasImage ();
		sf::Texture* GetCanvasTexture ();
		sf::Sprite* GetCanvasSprite ();
		void ApplyCanvas ();

		void Start ();
		void Stop ();
	};
}

#endif