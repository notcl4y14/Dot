#include <Dot/Main.h>
#include <Dot/DotApp.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

DotApp* Dot_DotApp;

int32_t main (int32_t argc, char** argv)
{
	Dot_DotApp = malloc(sizeof (DotApp));
	DotApp_Create(Dot_DotApp);

	DotApp_Delete(Dot_DotApp);
	free(Dot_DotApp);
	return 0;
}