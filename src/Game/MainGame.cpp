#include "PCH.hpp"
#include "Game/MainGame.hpp"
#include "Game/Player.hpp"
#include "core/GameWindow.hpp"

MainGame::MainGame(GameWindow* gameWindow)
{
	m_gameWindow = gameWindow;

	player = std::make_shared<Player>();

	m_v_drawableBuffer.push_back(player);

	m_gameWindow->SetDrawBuffer(m_v_drawableBuffer);
}

void MainGame::Start()
{

}
void MainGame::Update(float deltaTime)
{

}
void MainGame::HandleEvent(const std::optional<sf::Event>& evt)
{

}
