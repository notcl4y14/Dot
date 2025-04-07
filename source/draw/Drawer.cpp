#include <draw/Drawer.hpp>

sf::RenderTexture* Dot::Drawer::GetRenderTexture ()
{
	return renderTex;
}

void Dot::Drawer::SetRenderTexture (sf::RenderTexture* renderTex)
{
	this->renderTex = renderTex;
}