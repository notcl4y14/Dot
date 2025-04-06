#include <GameFrame.hpp>

#include <iostream>

Dot::GameFrame::GameFrame ()
{
	isRunning = false;
	updateCount = 0;
}

// 

void Dot::GameFrame::CreateWindow (const char* title, uint32_t width, uint32_t height)
{
	window.create(sf::VideoMode({width, height}), title);
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

void Dot::GameFrame::Start ()
{
	isRunning = true;
}

void Dot::GameFrame::Stop ()
{
	isRunning = false;
}