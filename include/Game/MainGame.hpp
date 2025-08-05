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
	void UpdateGroundMove(float deltaTime);
	void SpawnGroundTile();

	int GenRandomNumber(int min, int max);

private:
	std::vector<std::shared_ptr<sf::Drawable>> m_v_drawableBuffer;

	std::shared_ptr<Player> player;

	class GameWindow* m_gameWindow;

	std::vector<std::shared_ptr<sf::Sprite>> m_v_spriteGround;

	std::unique_ptr<sf::Image> m_groundImageAtlas;
	std::unique_ptr<sf::Texture> m_groundTextureAtlas;
};