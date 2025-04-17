#include <Dot/Main.h>
#include <Dot/CellChunk.h>
#include <Dot/DotApp.h>
#include <Dot/SFMLApp.h>

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
	sfRenderWindow* sfml_window = Dot_SFMLApp->window;
	sfEvent* sfml_event = &(Dot_SFMLApp->event);

	sfClock* sfml_clock = sfClock_create();
	sfTime sfml_time;

	Dot_DotApp->loop.enabled = true;

	while (sfRenderWindow_isOpen(sfml_window) == true)
	{
		// Process Events
		while (sfRenderWindow_pollEvent(sfml_window, sfml_event))
		{
			if (sfml_event->type == sfEvtClosed)
			{
				sfRenderWindow_close(sfml_window);
			}
		}

		// Update
		// Render

		CellChunk_Update(&(Dot_DotApp->cell_chunk));

		{
			Cell cell = (Cell) {1};
			CellChunk_SetCell(&(Dot_DotApp->cell_chunk), 16, 0, cell);
		}

		// Draw
		sfRenderWindow_clear(sfml_window, sfBlack);

		CellChunk_Render(&(Dot_DotApp->cell_chunk));

		sfRenderWindow_display(sfml_window);

		// Tick
		Dot_DotApp->loop.loop_count++;
		Dot_DotApp->loop.lps_counter++;

		sfml_time = sfClock_getElapsedTime(sfml_clock);

		if (sfTime_asMilliseconds(sfml_time) >= Dot_DotApp->loop.lps_update_time)
		{
			Dot_DotApp->loop.lps_current = Dot_DotApp->loop.lps_counter;
			Dot_DotApp->loop.lps_counter = 0;
			Dot_DotApp->loop.lps_update_time += 1000;

			printf("FPS: %d\n", Dot_DotApp->loop.lps_current);
		}

		// Delay
		sfml_time = sfMilliseconds(1000 / Dot_DotApp->loop.lps_target);
		sfSleep(sfml_time);
	}

	sfClock_destroy(sfml_clock);
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