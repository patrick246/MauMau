#pragma once
#include <SFML/Graphics.hpp>
#include <PGE/InputManager.h>
#include "Config.h"
#include "StateManager.h"
#include "TextureManager.h"

class GameApp
{
public:
	GameApp(Config& gameConfig);

	void run();

private:
	void update();
	void render();
	void handleWindowEvents();

public:
	sf::RenderWindow window;
	StateManager statemanager;
	TextureManager texturemanager;
	PGE::InputManager inputmanager;
	Config& config;

	float timestep;

private:
	sf::Clock m_clock;
	float m_accumulator;
};

