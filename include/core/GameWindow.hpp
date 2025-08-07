#pragma once
#include "Game/Layer.hpp"

class GameWindow
{
public:
	GameWindow(const WindowInfo& windowInfo);
	~GameWindow() = default;

	void Loop();
	void SetDrawBuffer(std::vector<Layer*>* drawableBuffer);

	float GetDeltaTime() const;
private:

	std::unique_ptr<sf::RenderWindow> m_gameWindow;
	sf::String m_WindowTitle;
	sf::VideoMode m_WindowSize;
	sf::State m_WindowState;
	sf::ContextSettings m_contextSettings;

	std::vector<Layer*>* m_v_drawableBuffer;

	sf::View CamView;

	float m_deltaTime;

};