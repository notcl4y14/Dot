#include <GameFrame.hpp>

Dot::GameFrame::GameFrame ()
{
	isRunning = false;
	updateCount = 0;

	// rtCellChunk.create();

	rCellChunk.SetRenderTexture(&rtCellChunk);
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

void Dot::GameFrame::InitCellChunk (uint32_t width, uint32_t height)
{
	cellChunk.Init(width, height);
	rCellChunk.cellChunk = &cellChunk;
	rtCellChunk.resize({width, height});
}

void Dot::GameFrame::DeleteCellChunk ()
{
	// delete[] cellChunk.cells;
	return;
}

Dot::CellChunk* Dot::GameFrame::GetCellChunk ()
{
	return &cellChunk;
}

// 

void Dot::GameFrame::DrawCellChunk ()
{
	rCellChunk.Draw();
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