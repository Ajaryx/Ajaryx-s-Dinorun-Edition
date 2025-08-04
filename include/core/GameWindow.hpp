#pragma once


class GameWindow
{
public:
	GameWindow(const WindowInfo& windowInfo);
	~GameWindow() = default;

	void Loop();
private:

	std::unique_ptr<sf::RenderWindow> m_gameWindow;
	sf::String m_WindowTitle;
	sf::VideoMode m_WindowSize;
	sf::State m_WindowState;
	sf::ContextSettings m_contextSettings;

};