#pragma once

#include <core/GameWindow.hpp>

class Game
{
public:
	Game(const WindowInfo& windowInfo);
	~Game() = default;

	void StartApplication();
private:

	std::unique_ptr<GameWindow> m_GameWindow;

};