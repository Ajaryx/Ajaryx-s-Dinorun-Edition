#include "PCH.hpp"
#include "core/Game.hpp"

Game::Game(const WindowInfo& windowInfo)
{
	m_GameWindow = std::make_unique<GameWindow>(windowInfo);
}

void Game::StartApplication()
{
	m_GameWindow->Loop();
}
