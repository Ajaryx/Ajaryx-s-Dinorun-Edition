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
	void HandleJumpPlayer(float deltaTime);
	int GenRandomNumber(int min, int max);
	void HandlePlayerJump();
	void StartSpawnCactusTimer();
	void SpawnCactus();
	void CheckPlayerCollisionCac();
	float GenRandomNumber(float min, float max);
private:
	std::vector<Layer*> m_v_drawableBuffer;
	std::unique_ptr<std::thread> spawnCacThread;
	std::shared_ptr<sf::RectangleShape> m_player;
	
	Layer* m_playerLayer;

	class GameWindow* m_gameWindow;

	Layer* m_spriteGroundLayer;
	std::vector<std::shared_ptr<sf::Sprite>> m_v_ground;

	Layer* m_spriteCactusLayer;
	std::vector<std::shared_ptr<sf::Sprite>> m_v_cactus;

	std::unique_ptr<sf::Image> m_groundImageAtlas;
	std::unique_ptr<sf::Texture> m_groundTextureAtlas;
	std::unique_ptr<sf::Texture> m_cacSprite;
private:

	int score = 0;
	int highScore = 0;
	bool m_IsJumping = false;
	float groundSpeed = 300.f;
	float m_PlayerFallVelocity = 0.f;
	const float m_JumpHeight = 20.f;
	bool m_grounded = false;
	const float m_PlayerFallVelocityMultiplyer = 50.f;
	const float m_PlayerJumpVelocityMultiplyer = 70.f;

	int minCacSpawner = 700;
	int maxCacSpawner = 1500;

	std::shared_ptr<sf::Text> m_scoreText;
	std::shared_ptr<sf::Text> m_highScore;
	std::unique_ptr<sf::Font> m_font;
};