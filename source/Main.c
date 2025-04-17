#include <Dot/Main.h>
#include <Dot/DotApp.h>
#include <Dot/SFMLApp.h>

#include <SFML/Window.h>

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
	Dot_SFMLApp->window = sfWindow_create(
		(sfVideoMode) {800, 600},
		"Dot",
		sfDefaultStyle,
		NULL);
}

void Main_Loop ()
{
	sfWindow* sfml_window = Dot_SFMLApp->window;
	sfEvent* sfml_event = &(Dot_SFMLApp->event);

	while (sfWindow_isOpen(sfml_window) == true)
	{
		while (sfWindow_pollEvent(sfml_window, sfml_event))
		{
			if (sfml_event->type == sfEvtClosed)
			{
				sfWindow_close(sfml_window);
			}
		}
	}
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