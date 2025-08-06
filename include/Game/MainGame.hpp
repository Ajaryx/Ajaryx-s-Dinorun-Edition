#pragma once


class Layer;
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
	void UpdatePlayerPhysics(float deltaTime);

	int GenRandomNumber(int min, int max);
	void HandlePlayerJump();
private:
	std::vector<Layer*> m_v_drawableBuffer;

	std::shared_ptr<sf::RectangleShape> m_player;
	
	Layer* m_playerLayer;

	class GameWindow* m_gameWindow;

	Layer* m_spriteGroundLayer;
	std::vector<std::shared_ptr<sf::Sprite>> m_v_ground;

	std::unique_ptr<sf::Image> m_groundImageAtlas;
	std::unique_ptr<sf::Texture> m_groundTextureAtlas;

private:

	float groundSpeed = 150.f;
	float m_PlayerFallVelocity = 0.f;
	bool m_grounded = false;
	const float m_PlayerFallVelocityMultiplyer = 50.f;
};