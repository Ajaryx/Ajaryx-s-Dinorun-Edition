#include "PCH.hpp"
#include "core/Game.hpp"

int main()
{
	Game game(WindowInfo{ "Test", sf::VideoMode({800, 600}), sf::State::Windowed, sf::ContextSettings::Default });
	game.StartApplication();

	return EXIT_SUCCESS;
}