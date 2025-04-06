#include <render/Renderer.hpp>

sf::RenderTexture* Dot::Renderer::GetRenderTexture ()
{
	return renderTex;
}

void Dot::Renderer::SetRenderTexture (sf::RenderTexture* renderTex)
{
	this->renderTex = renderTex;
}