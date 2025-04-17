#ifndef DOT_SFMLAPP_H
#define DOT_SFMLAPP_H

#include <SFML/Window.h>

struct         SFMLApp;
typedef struct SFMLApp SFMLApp;

struct SFMLApp
{
	sfWindow* window;
	sfEvent event;
};

void SFMLApp_Create (SFMLApp* sfml);
void SFMLApp_Delete (SFMLApp* sfml);

#endif