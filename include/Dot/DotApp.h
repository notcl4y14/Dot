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

void DotApp_create (DotApp* dot);
void DotApp_delete (DotApp* dot);

DotApp* DotApp_create_a (DotApp* dot);
void DotApp_delete_a (DotApp* dot);

#endif