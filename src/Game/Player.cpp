#include "PCH.hpp"
#include "Game/Player.hpp"


Player::Player()
{
	//m_playerTexture = std::make_unique<sf::Texture>();
	//m_playerSprite = std::make_unique<sf::Sprite>(m_playerSprite);
	m_playerSprite = std::make_unique<sf::RectangleShape>(sf::Vector2f(100.f, 100.f));
	
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_playerSprite);
}
