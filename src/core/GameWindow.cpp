#include "PCH.hpp"
#include "core/GameWindow.hpp"

GameWindow::GameWindow(const WindowInfo& windowInfo)
{
	m_WindowTitle = windowInfo.title;
	m_WindowSize = windowInfo.windowSize;
	m_WindowState = windowInfo.state;
	m_contextSettings = windowInfo.contextSettings;

	m_gameWindow = std::make_unique<sf::RenderWindow>(m_WindowSize, m_WindowTitle, m_WindowState, m_contextSettings);

}
void GameWindow::Loop()
{
	while (m_gameWindow->isOpen())
	{
		while (std::optional<sf::Event> evt = m_gameWindow->pollEvent())
		{
			if (evt->is<sf::Event::Closed>())
			{
				m_gameWindow->close();
			}
		}
		m_gameWindow->clear();


		m_gameWindow->display();
	}
}
