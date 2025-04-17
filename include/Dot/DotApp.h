#ifndef DOT_DOTAPP_H
#define DOT_DOTAPP_H

#include <stdint.h>
#include <stdbool.h>

struct         DotApp;
typedef struct DotApp DotApp;

struct DotApp
{
	bool is_running;
};

void DotApp_Create (DotApp* dot);
void DotApp_Delete (DotApp* dot);;

#endif