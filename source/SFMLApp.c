#include <Dot/SFMLApp.h>

#include <SFML/Graphics.h>

void SFMLApp_Create (SFMLApp* sfml)
{
	sfml->rect = sfRectangleShape_create();
}

void SFMLApp_Delete (SFMLApp* sfml)
{
	sfRectangleShape_destroy(sfml->rect);
}