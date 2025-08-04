#pragma once

#include "Game/Player.hpp"

class MainGame
{
public:
	MainGame(class GameWindow* gameWindow);
	~MainGame() = default;

	void Start();
	void Update(float deltaTime);
	void HandleEvent(const std::optional<sf::Event>& evt);
private:

	std::vector<std::shared_ptr<sf::Drawable>> m_v_drawableBuffer;

	std::shared_ptr<Player> player;

	class GameWindow* m_gameWindow;
};