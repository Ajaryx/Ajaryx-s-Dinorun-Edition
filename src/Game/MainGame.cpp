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

	m_spriteGroundLayer = new Layer();
	m_playerLayer = new Layer();

	m_player = std::make_shared<sf::RectangleShape>(sf::Vector2f(100.f, 100.f));

	m_playerLayer->AddDrawable(m_player);
	m_v_drawableBuffer.push_back(m_spriteGroundLayer);
	m_v_drawableBuffer.push_back(m_playerLayer);

	

	m_gameWindow->SetDrawBuffer(&m_v_drawableBuffer);
	
}

void MainGame::Start()
{
	for (size_t i = 0; i < 20; i++)
	{
		SpawnGroundTile();
	}
}
void MainGame::Update(float deltaTime)
{
	UpdateGroundMove(deltaTime);
	UpdatePlayerPhysics(deltaTime);
}
void MainGame::HandleEvent(const std::optional<sf::Event>& evt)
{

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
void MainGame::UpdatePlayerPhysics(float deltaTime)
{
	if (!m_grounded)
	{
		m_PlayerFallVelocity += m_PlayerFallVelocityMultiplyer;
		m_player->move(sf::Vector2f(0.f, m_PlayerFallVelocity * deltaTime));

		for (const auto& item : m_v_ground)
		{
			sf::FloatRect groundBounds = item->getGlobalBounds();
			if (m_player->getGlobalBounds().findIntersection(sf::FloatRect(sf::Vector2f(groundBounds.position.x, groundBounds.position.y + 10), sf::Vector2f(groundBounds.size.x, groundBounds.size.y))))
			{
				m_grounded = true;
				return;
			}
		}
		
	}
}