#include "PCH.hpp"
#include "Game/MainGame.hpp"
#include "core/GameWindow.hpp"
#include "TextureAtlaseDefines.hpp"
#include "Game/Layer.hpp"

MainGame::MainGame(GameWindow* gameWindow)
{
	m_gameWindow = gameWindow;

	m_groundImageAtlas = std::make_unique<sf::Image>("TextureAtlas.png");
	m_groundTextureAtlas = std::make_unique<sf::Texture>(*m_groundImageAtlas);
	m_cacSprite = std::make_unique<sf::Texture>("cactus.png");
	m_font = std::make_unique<sf::Font>("Roboto\\static\\Roboto-Black.ttf");
	m_scoreText = std::make_shared<sf::Text>(*m_font, "Score: 0");
	m_highScore = std::make_shared<sf::Text>(*m_font, "High Score: 0");
	m_highScore->setPosition(sf::Vector2f(400.f, 0.f));
	m_spriteGroundLayer = new Layer();
	m_spriteCactusLayer = new Layer();
	m_playerLayer = new Layer();

	m_player = std::make_shared<sf::RectangleShape>(sf::Vector2f(50.f, 70.f));
	
	m_playerLayer->AddDrawable(m_player);
	m_playerLayer->AddDrawable(m_scoreText);
	m_playerLayer->AddDrawable(m_highScore);
	m_v_drawableBuffer.push_back(m_spriteGroundLayer);
	m_v_drawableBuffer.push_back(m_spriteCactusLayer);
	m_v_drawableBuffer.push_back(m_playerLayer);

	m_gameWindow->SetDrawBuffer(&m_v_drawableBuffer);
	
}

void MainGame::Start()
{
	for (size_t i = 0; i < 20; i++)
	{
		SpawnGroundTile();
	}
	spawnCacThread = std::make_unique<std::thread>([&]() {StartSpawnCactusTimer(); });
}
void MainGame::Update(float deltaTime)
{
	UpdateGroundMove(deltaTime);
	UpdatePlayerPhysics(deltaTime);
	HandleJumpPlayer(deltaTime);
	CheckPlayerCollisionCac();
}
void MainGame::HandleEvent(const std::optional<sf::Event>& evt)
{
	if (evt->is<sf::Event::KeyPressed>())
	{
		auto keyPress = evt->getIf<sf::Event::KeyPressed>()->code;

		if (keyPress == sf::Keyboard::Key::Space && m_grounded)
		{
			m_IsJumping = true;
		}
	}
}
void MainGame::StartSpawnCactusTimer()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(GenRandomNumber(minCacSpawner, maxCacSpawner)));
		SpawnCactus();
		score += 1;
		m_scoreText->setString("Score: " + std::to_string(score));
		if (score > highScore)
		{
			highScore = score;
			m_highScore->setString("High Score: " + std::to_string(highScore));
		}
		switch (score)
		{
		case 10:
			groundSpeed += 50.f;
			minCacSpawner -= 100;
			maxCacSpawner -= 100;
			break;
		case 20:
			groundSpeed += 50.f;
			minCacSpawner -= 100;
			maxCacSpawner -= 100;
			break;
		case 30:
			groundSpeed += 50.f;
			minCacSpawner -= 100;
			maxCacSpawner -= 100;
			break;
		case 40:
			minCacSpawner -= 100;
			maxCacSpawner -= 100;
			break;
		case 50:
			minCacSpawner -= 100;
			maxCacSpawner -= 100;
			break;
		}
	}
}
void MainGame::SpawnCactus()
{
	auto& cac = std::make_shared<sf::Sprite>(*m_cacSprite);
	cac->setPosition(sf::Vector2f(800.f, 250.f));
	m_v_cactus.push_back(cac);
	m_spriteCactusLayer->AddDrawable(cac);
}
void MainGame::UpdateGroundMove(float deltaTime)
{
	for (auto it = m_v_ground.begin(); it != m_v_ground.end();)
	{
		it->get()->move(sf::Vector2f(-groundSpeed * deltaTime, 0.f));

		if (it->get()->getPosition().x + it->get()->getScale().x * 16 <= 0.f)
		{
			it = m_v_ground.erase(it);
			m_spriteGroundLayer->DeleteDrawable(m_spriteGroundLayer->GetDrawablesLayer().cbegin());
			sf::Vector2i desertTileLoc = desertSpriteVec[GenRandomNumber(0, desertSpriteVec.size() - 1)];
			auto& newTile = std::make_shared<sf::Sprite>(*m_groundTextureAtlas, sf::IntRect(desertTileLoc, sf::Vector2i(16, 16)));
			m_spriteGroundLayer->AddDrawable(newTile);
			m_v_ground.push_back(newTile);
			auto& lastTile = m_v_ground[m_v_ground.size() - 2];
			newTile->setScale(sf::Vector2f(4.f, 4.f));
			newTile->setPosition(sf::Vector2f(lastTile->getPosition().x + lastTile->getScale().x * 16, 300.f));
		}
		else
		{
			it++;
		}
	}
	for (auto it = m_v_cactus.begin(); it != m_v_cactus.end();)
	{
		it->get()->move(sf::Vector2f(-groundSpeed * deltaTime, 0.f));

		if (it->get()->getPosition().x + it->get()->getScale().x * 100 <= 0.f)
		{
			it = m_v_cactus.erase(it);
			m_spriteCactusLayer->DeleteDrawable(m_spriteCactusLayer->GetDrawablesLayer().cbegin());
			sf::Vector2i desertTileLoc = desertSpriteVec[GenRandomNumber(0, desertSpriteVec.size() - 1)];
	
		}
		else
		{
			it++;
		}
	}
}
void MainGame::CheckPlayerCollisionCac()
{
	for (const auto& item : m_v_cactus)
	{
		if (m_player->getGlobalBounds().findIntersection(item->getGlobalBounds()))
		{
			score = 0;
			m_scoreText->setString("Score: " + std::to_string(score));
		}
	}
}
void MainGame::SpawnGroundTile()
{
	sf::Vector2i desertTileLoc = desertSpriteVec[GenRandomNumber(0, desertSpriteVec.size()-1)];

	auto& newTile = std::make_shared<sf::Sprite>(*m_groundTextureAtlas, sf::IntRect(desertTileLoc, sf::Vector2i(16, 16)));
	m_spriteGroundLayer->AddDrawable(newTile);
	m_v_ground.push_back(newTile);

	newTile->setScale(sf::Vector2f(4.f, 4.f));

	if (m_v_ground.size() == 1)
	{
		newTile->setPosition(sf::Vector2f(0.f, 300.f));
	}
	else
	{
		auto& lastTile = m_v_ground[m_v_ground.size() - 2];

		newTile->setPosition(sf::Vector2f(lastTile->getPosition().x + lastTile->getScale().x * 16, 300.f));

	}
	
}
int MainGame::GenRandomNumber(int min, int max)
{
	std::random_device seed;
	std::mt19937 gen(seed());

	std::uniform_int_distribution dist(min, max);

	return dist(gen);
}
float MainGame::GenRandomNumber(float min, float max)
{
	std::random_device seed;
	std::mt19937 gen(seed());

	std::uniform_real_distribution dist(min, max);

	return dist(gen);
}
void MainGame::UpdatePlayerPhysics(float deltaTime)
{
	if (!m_grounded && !m_IsJumping)
	{
		m_PlayerFallVelocity += m_PlayerFallVelocityMultiplyer * deltaTime;
		m_player->move(sf::Vector2f(0.f, m_PlayerFallVelocity));

		for (const auto& item : m_v_ground)
		{
			sf::FloatRect groundBounds = item->getGlobalBounds();
			if (m_player->getGlobalBounds().findIntersection(sf::FloatRect(sf::Vector2f(groundBounds.position.x, groundBounds.position.y + 10), sf::Vector2f(groundBounds.size.x, groundBounds.size.y))))
			{
				m_grounded = true;
				m_PlayerFallVelocity = 0.f;
				return;
			}
		}
		
	}
}
void MainGame::HandleJumpPlayer(float deltaTime)
{
	if (m_IsJumping)
	{
		if (m_PlayerFallVelocity <= m_JumpHeight)
		{
			m_grounded = false;
			m_PlayerFallVelocity += m_PlayerJumpVelocityMultiplyer * deltaTime;
			m_player->move(sf::Vector2f(0.f, -m_PlayerFallVelocity));
			
		}
		else
		{
			m_IsJumping = false;
			m_PlayerFallVelocity = 0.f;
		}
		
	}
}