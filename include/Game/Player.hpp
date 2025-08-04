#pragma once

class Player : public sf::Drawable
{
public:
	Player();
	~Player() = default;

private:

	// Inherited via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//std::unique_ptr<sf::Sprite> m_playerSprite;
	//std::unique_ptr<sf::Texture> m_playerTexture;
	std::unique_ptr<sf::RectangleShape> m_playerSprite;
};