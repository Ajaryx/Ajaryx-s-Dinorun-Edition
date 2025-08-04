#include "PCH.hpp"
#include "core/GameWindow.hpp"

int main()
{
	
	GameWindow window(WindowInfo{ "Test", sf::VideoMode({800, 600}), sf::State::Windowed, sf::ContextSettings::Default });
	window.Loop();
	return EXIT_SUCCESS;
}