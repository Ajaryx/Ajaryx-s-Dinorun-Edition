#pragma once
#include <SFML/Graphics.hpp>

struct WindowInfo
{
	sf::String title;
	sf::VideoMode windowSize;
	sf::State state;
	sf::ContextSettings contextSettings;
};