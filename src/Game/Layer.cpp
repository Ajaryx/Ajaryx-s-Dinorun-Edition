#include "PCH.hpp"
#include "Game/Layer.hpp"


void Layer::AddDrawable(const std::shared_ptr<sf::Drawable>& drawable)
{
	m_layerBuffer.push_back(drawable);
}
void Layer::DeleteDrawable(std::vector<std::shared_ptr<sf::Drawable>>::const_iterator it)
{
	m_layerBuffer.erase(it);
}
const std::vector<std::shared_ptr<sf::Drawable>>& Layer::GetDrawablesLayer() const
{
	return m_layerBuffer;
}
