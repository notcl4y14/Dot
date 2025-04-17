#include <Dot/Main.h>
#include <Dot/DotApp.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

DotApp* Dot_DotApp;

int32_t main (int32_t argc, char** argv)
{
	printf("Hello World!\n");

	Dot_DotApp = malloc(sizeof (DotApp));
	DotApp_Create(Dot_DotApp);

	printf("_DotApp->is_running = %d\n", Dot_DotApp->is_running);

	DotApp_Delete(Dot_DotApp);
	return 0;
}