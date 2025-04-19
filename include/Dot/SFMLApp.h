#ifndef DOT_SFMLAPP_H
#define DOT_SFMLAPP_H

#include <SFML/Graphics.h>

struct         SFMLApp;
typedef struct SFMLApp SFMLApp;

struct SFMLApp
{
	sfRenderWindow* window;
	sfEvent event;

	sfRectangleShape* rect;
};

void SFMLApp_Create (SFMLApp* sfml);
void SFMLApp_Delete (SFMLApp* sfml);

#endif