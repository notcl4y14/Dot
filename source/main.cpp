#include <main.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

int32_t main (int32_t argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode({800, 600}), "Dot");

	// sf::Event event;
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.display();
	}

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