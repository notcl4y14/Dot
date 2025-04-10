#ifndef DOT_RENDER_HPP
#define DOT_RENDER_HPP

#include <SFML/Graphics.hpp>

namespace Dot
{
	class Drawer
	{
	protected:
		sf::RenderTexture* renderTex;

	public:
		sf::RenderTexture* GetRenderTexture ();
		void SetRenderTexture (sf::RenderTexture* renderTex);

		void Draw ();
	};
}

#endif