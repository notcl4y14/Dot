#include <main.hpp>
#include <GameFrame.hpp>
#include <cells/Cell.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

Dot::GameFrame frameDot;

int32_t main (int32_t argc, char* argv[])
{
	frameDot.CreateWindow("Dot", 800, 600);
	frameDot.Start();

	sf::RenderWindow* window = frameDot.GetWindow();

	Dot::cells::Cell cell(1, 0xffff00ff);

	// sf::Event event;
	while (frameDot.isRunning)
	{
		/* Process Events
		 */

		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				frameDot.Stop();
		}

		/* Update
		 */

		/* Draw
		 */

		window->clear();
		sf::RectangleShape rect;
		rect.setPosition({10, 10});
		rect.setSize({25, 25});
		rect.setFillColor((sf::Color)cell.color);
		window->draw(rect);
		window->display();
	}

	window->close();

	return 0;
}

void output_args (int32_t argc, char* argv[])
{
	uint32_t loopIdx = 0;
	uint32_t loopEnd = argc;

	std::cout << "Hello World!\n";
	std::cout << "Arguments Count: " << argc << "\n";
	std::cout << "Arguments:\n";

	while (loopIdx != loopEnd)
	{
		std::cout << "\t" << argv[loopIdx] << "\n";
		loopIdx++;
	}
}