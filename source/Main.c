#include <Dot/Main.h>
#include <Dot/CellChunk.h>
#include <Dot/DotApp.h>
#include <Dot/SFMLApp.h>
#include <Dot/System.h>

#include <SFML/Graphics.h>
#include <SFML/System.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

DotApp* Dot_DotApp;
SFMLApp* Dot_SFMLApp;

int32_t main (int32_t argc, char** argv)
{
	Main_Setup();

	Main_Loop();

	Main_Quit();

	return 0;
}

void Main_Setup ()
{
	System_Init();

	// Allocate global variables
	Dot_DotApp = malloc(sizeof (DotApp));
	Dot_SFMLApp = malloc(sizeof (SFMLApp));

	// Initialize global variables
	DotApp_Create(Dot_DotApp);
	SFMLApp_Create(Dot_SFMLApp);

	// Create Window
	Dot_SFMLApp->window = sfRenderWindow_create(
		(sfVideoMode) {800, 600},
		"Dot",
		sfDefaultStyle,
		NULL);

	// Initialize cell chunk
	CellChunk_Init(&(Dot_DotApp->cell_chunk), 32, 32);

	// Initialize loop managers
	Dot_DotApp->loop.lps_target = 60;
	Dot_DotApp->loop.loop_count = 0;
}

void Main_Loop ()
{
	sfRenderWindow* const sfml_window = Dot_SFMLApp->window;
	LoopManager* const dot_loop = &(Dot_DotApp->loop);

	Dot_DotApp->is_running = true;
	Dot_DotApp->loop.enabled = true;
	Dot_DotApp->loop.lps_update_time = System_GetTimeMS();

	while (Dot_DotApp->is_running)
	{
		// Process Events
		Main_ProcessEvts();

		// Update
		// Render
		Main_Update();
		Main_Render();

		// Tick
		uint32_t const elapsed_time = System_GetTimeMS();
		bool const should_render_fps = (elapsed_time >= dot_loop->lps_update_time);

		LoopManager_Tick(dot_loop);

		if (should_render_fps == true)
		{
			printf("FPS: %d\n", dot_loop->lps_current);
		}

		// Delay
		uint32_t const sleep_time = (1000 / Dot_DotApp->loop.lps_target);
		System_SleepMS(sleep_time);
	}

	sfRenderWindow_close(sfml_window);
}

void Main_Quit ()
{
	// Delete global variables
	DotApp_Delete(Dot_DotApp);
	SFMLApp_Delete(Dot_SFMLApp);

	// Free global variables
	free(Dot_DotApp);
	free(Dot_SFMLApp);

	// Set global variables' pointers to NULL
	Dot_DotApp = NULL;
	Dot_SFMLApp = NULL;
}

void Main_ProcessEvts ()
{
	sfRenderWindow* const sfml_window = Dot_SFMLApp->window;
	sfEvent* const sfml_event = &(Dot_SFMLApp->event);

	while (sfRenderWindow_pollEvent(sfml_window, sfml_event))
	{
		if (sfml_event->type == sfEvtClosed)
		{
			Dot_DotApp->is_running = false;
		}
	}
}

void Main_Update ()
{
	CellChunk* const cell_chunk = &(Dot_DotApp->cell_chunk);

	CellChunk_Update(cell_chunk);

	// Add sand cell each tick
	{
		Cell cell = (Cell) {1};
		CellChunk_SetCell(cell_chunk, 16, 0, cell);
	}
}

void Main_Render ()
{
	sfRenderWindow* const sfml_window = Dot_SFMLApp->window;
	CellChunk* const cell_chunk = &(Dot_DotApp->cell_chunk);

	sfRenderWindow_clear(sfml_window, sfBlack);

	CellChunk_Render(cell_chunk);

	sfRenderWindow_display(sfml_window);
}