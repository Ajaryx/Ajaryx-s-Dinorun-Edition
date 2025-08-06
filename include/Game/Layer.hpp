#pragma once

class Layer
{
public:
	Layer() = default;
	~Layer() = default;

	void AddDrawable(const std::shared_ptr<sf::Drawable>& drawable);
	void DeleteDrawable(std::vector<std::shared_ptr<sf::Drawable>>::const_iterator it);
	const std::vector<std::shared_ptr<sf::Drawable>>& GetDrawablesLayer() const;

private:
	std::vector<std::shared_ptr<sf::Drawable>> m_layerBuffer;
};