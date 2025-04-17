#include <Dot/DotApp.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void DotApp_create (DotApp* dot)
{
	dot->is_running = false;
}

void DotApp_delete (DotApp* dot)
{
	dot->is_running = false;
}

inline DotApp* DotApp_create_a (DotApp* dot)
{
	dot = malloc(sizeof(DotApp));
	DotApp_create(dot);
	return dot;
}

inline void DotApp_delete_a (DotApp* dot)
{
	DotApp_delete(dot);
	free(dot);
}