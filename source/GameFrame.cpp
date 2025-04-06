#include <GameFrame.hpp>

#include <iostream>

Dot::GameFrame::GameFrame (): canvas_spr(canvas_tex)
{
	isRunning = false;
	updateCount = 0;
}

// 

void Dot::GameFrame::CreateWindow (const char* title, uint32_t width, uint32_t height)
{
	window.create(sf::VideoMode({width, height}), title);
	canvas_img.resize({width, height});
}

void Dot::GameFrame::CloseWindow ()
{
	window.close();
}

sf::RenderWindow* Dot::GameFrame::GetWindow ()
{
	return &window;
}

// 

sf::Image* Dot::GameFrame::GetCanvasImage ()
{
	return &canvas_img;
}

sf::Texture* Dot::GameFrame::GetCanvasTexture ()
{
	return &canvas_tex;
}

sf::Sprite* Dot::GameFrame::GetCanvasSprite ()
{
	return &canvas_spr;
}

void Dot::GameFrame::ApplyCanvas ()
{
	uint8_t success = canvas_tex.loadFromImage(canvas_img);

	if (!success)
	{
		std::exit(1);
	}

	canvas_spr.setTexture(canvas_tex);
}

// 

void Dot::GameFrame::Start ()
{
	isRunning = true;
}

void Dot::GameFrame::Stop ()
{
	isRunning = false;
}