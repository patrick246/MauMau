#pragma once
#include <SFML/Graphics.hpp>
#include <PGE/InputManager.h>
#include "Config.h"
#include "StateManager.h"
#include "ResourceManager.h"

class GameApp
	:	sf::NonCopyable
{
public:
	GameApp(Config& gameConfig);

	void run();

private:
	void update();
	void render();
	void handleWindowEvents();
	void handleResize();

public:
	sf::RenderWindow	window;
	StateManager		statemanager;
	TextureManager		texturemanager;
	FontManager			fontmanager;
	pge::InputManager	inputmanager;
	Config&				config;

	float				timestep;

private:
	sf::Clock			m_clock;
	float				m_accumulator;
};

