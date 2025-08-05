#include "PCH.hpp"
#include "Game/MainGame.hpp"
#include "Game/Player.hpp"
#include "core/GameWindow.hpp"
#include "TextureAtlaseDefines.hpp"

MainGame::MainGame(GameWindow* gameWindow)
{
	m_gameWindow = gameWindow;

	m_groundImageAtlas = std::make_unique<sf::Image>("TextureAtlas.png");
	m_groundTextureAtlas = std::make_unique<sf::Texture>(*m_groundImageAtlas);

	player = std::make_shared<Player>();

	//m_v_drawableBuffer.push_back(player);

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
}
void MainGame::HandleEvent(const std::optional<sf::Event>& evt)
{

}

void MainGame::UpdateGroundMove(float deltaTime)
{

}
void MainGame::SpawnGroundTile()
{
	sf::Vector2i desertTileLoc = desertSpriteVec[GenRandomNumber(0, desertSpriteVec.size()-1)];
	m_v_spriteGround.push_back(std::make_shared<sf::Sprite>(*m_groundTextureAtlas, sf::IntRect(desertTileLoc, sf::Vector2i(16, 16))));

	auto& newestSprite = m_v_spriteGround[m_v_spriteGround.size() - 1];
	newestSprite->setScale(sf::Vector2f(4.f, 4.f));
	if (m_v_spriteGround.size() == 1)
	{
		newestSprite->setPosition({ 0, 300 });
	}
	else
	{
		auto& beforeSprite = m_v_spriteGround[m_v_spriteGround.size() - 2];
		newestSprite->setPosition(sf::Vector2f(beforeSprite->getPosition().x + beforeSprite->getScale().x * 16, 300));
	}
	m_v_drawableBuffer.push_back(newestSprite);
}
int MainGame::GenRandomNumber(int min, int max)
{
	std::random_device seed;
	std::mt19937 gen(seed());

	std::uniform_int_distribution dist(min, max);

	return dist(gen);
}