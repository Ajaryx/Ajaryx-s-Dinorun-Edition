#pragma once


class GameWindow
{
public:
	GameWindow(const WindowInfo& windowInfo);
	~GameWindow() = default;

	void Loop();
	void SetDrawBuffer(const std::vector<std::shared_ptr<sf::Drawable>>& drawableBuffer);
private:

	std::unique_ptr<sf::RenderWindow> m_gameWindow;
	sf::String m_WindowTitle;
	sf::VideoMode m_WindowSize;
	sf::State m_WindowState;
	sf::ContextSettings m_contextSettings;

	std::vector<std::shared_ptr<sf::Drawable>> m_v_drawableBuffer;

};