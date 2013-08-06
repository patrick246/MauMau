#pragma once
#include <SFML/Graphics.hpp>
#include <PGE/InputManager.h>

class GameApp
{
public:
	GameApp(void);

	void run();

private:
	void update();
	void render();
	void handleWindowEvents();

public:
	sf::RenderWindow window;
	// StateManager
	// TextureManager
	PGE::InputManager input;
};

