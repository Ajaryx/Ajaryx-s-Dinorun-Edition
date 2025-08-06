#include "PCH.hpp"
#include "core/GameWindow.hpp"
#include "Game/MainGame.hpp"

GameWindow::GameWindow(const WindowInfo& windowInfo)
{
	m_WindowTitle = windowInfo.title;
	m_WindowSize = windowInfo.windowSize;
	m_WindowState = windowInfo.state;
	m_contextSettings = windowInfo.contextSettings;

	m_gameWindow = std::make_unique<sf::RenderWindow>(m_WindowSize, m_WindowTitle, m_WindowState, m_contextSettings);

	CamView = sf::View(m_gameWindow->getDefaultView());
	CamView.zoom(1.f);
	m_gameWindow->setView(CamView);
}
void GameWindow::Loop()
{
	m_gameWindow->setFramerateLimit(60);

	MainGame mainGame(this);

	mainGame.Start();
	sf::Clock clock;
	while (m_gameWindow->isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		while (std::optional<sf::Event> evt = m_gameWindow->pollEvent())
		{
			if (evt->is<sf::Event::Closed>())
			{
				m_gameWindow->close();
			}
			mainGame.HandleEvent(evt);
		}
		mainGame.Update(deltaTime);
		m_gameWindow->clear();
		for (const auto& item : *m_v_drawableBuffer)
		{
			for(const auto& item2 : item->GetDrawablesLayer())
			m_gameWindow->draw(*item2);
		}


		m_gameWindow->display();
	}
}

void GameWindow::SetDrawBuffer(std::vector<Layer*>* drawableBuffer)
{
	m_v_drawableBuffer = drawableBuffer;
}
