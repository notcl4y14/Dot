#include <Dot/DotApp.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void DotApp_Create (DotApp* dot)
{
	dot->is_running = false;
}

void DotApp_Delete (DotApp* dot)
{
	dot->is_running = false;
}