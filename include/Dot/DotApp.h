#ifndef DOT_DOTAPP_H
#define DOT_DOTAPP_H

#include <Dot/LoopManager.h>

#include <stdint.h>
#include <stdbool.h>

struct         DotApp;
typedef struct DotApp DotApp;

struct DotApp
{
	bool is_running;

	LoopManager loop;
};

void DotApp_Create (DotApp* dot);
void DotApp_Delete (DotApp* dot);;

#endif