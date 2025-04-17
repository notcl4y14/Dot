#include <Dot/Main.h>
#include <Dot/DotApp.h>

#include <stdio.h>
#include <stdint.h>

DotApp* _DotApp;

int32_t main (int32_t argc, char** argv)
{
	printf("Hello World!\n");

	_DotApp = malloc(sizeof (DotApp));
	DotApp_create(_DotApp);

	printf("_DotApp->is_running = %d\n", _DotApp->is_running);

	DotApp_delete(_DotApp);
	return 0;
}