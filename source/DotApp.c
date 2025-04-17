#include <Dot/DotApp.h>
#include <Dot/LoopManager.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void DotApp_Create (DotApp* dot)
{
	dot->is_running = false;

	LoopManager_Create(&dot->loop);
}

void DotApp_Delete (DotApp* dot)
{
	dot->is_running = false;

	LoopManager_Delete(&dot->loop);
}