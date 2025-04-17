#include <Dot/Main.h>
#include <Dot/DotApp.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

DotApp* Dot_DotApp;

int32_t main (int32_t argc, char** argv)
{
	Main_Setup();
	
	Main_Quit();

	return 0;
}

void Main_Setup ()
{
	// Allocate global variables
	Dot_DotApp = malloc(sizeof (DotApp));

	// Initialize global variables
	DotApp_Create(Dot_DotApp);
}

void Main_Quit ()
{
	// Delete global variables
	DotApp_Delete(Dot_DotApp);

	// Free global variables
	free(Dot_DotApp);

	// Set global variables' pointers to NULL
	Dot_DotApp = NULL;
}