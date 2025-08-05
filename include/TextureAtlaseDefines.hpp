#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

constexpr sf::Vector2i DESERT_TILE1 = sf::Vector2i(32, 0);
constexpr sf::Vector2i DESERT_TILE2 = sf::Vector2i(32, 0);
constexpr sf::Vector2i DESERT_TILE3 = sf::Vector2i(32, 48);
constexpr sf::Vector2i DESERT_TILE4 = sf::Vector2i(48, 32);
constexpr sf::Vector2i DESERT_TILE5 = sf::Vector2i(32, 80);
constexpr sf::Vector2i DESERT_TILE6 = sf::Vector2i(48, 80);


std::vector<sf::Vector2i> desertSpriteVec = 
{
	sf::Vector2i(16, 0),
	sf::Vector2i(16, 0),
	sf::Vector2i(16, 48),
	sf::Vector2i(32, 48),
	sf::Vector2i(16, 80),
	sf::Vector2i(32, 80),

};
