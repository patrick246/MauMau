#include "GameApp.h"

// STATES
#include "MainMenuState.h"
// STATES END

GameApp::GameApp(Config& gameConfig)
	: inputmanager(window)
	, config(gameConfig)
	, timestep(1.f / 60.f)
	, m_accumulator(0.f)
{
	// Create the game window with values from the config file
	window.create(sf::VideoMode(config.get<int>("resX"), config.get<int>("resY")), config.get<std::string>("windowtitle"), sf::Style::Default);
	
	// Register the game states
	statemanager.registerState("MainMenuState", std::unique_ptr<State>(new MainMenuState(*this)));

	// Push the starting state on the stack
	statemanager.pushState(config.get<std::string>("startState"));
}

void GameApp::run()
{
	while(window.isOpen())
	{
		handleWindowEvents();
		update();
		render();
	}
}

void GameApp::update()
{
	sf::Time frametime = m_clock.restart();
	m_accumulator += frametime.asSeconds();
	
	while(m_accumulator >= timestep)
	{
		statemanager.update(timestep);
		inputmanager.update();
		m_accumulator -= timestep;
	}
}

void GameApp::render()
{
	window.clear();
	window.draw(statemanager);
	window.display();
}

void GameApp::handleWindowEvents()
{
	sf::Event e;
	while(window.pollEvent(e))
	{
		if(e.type == sf::Event::Closed)
			window.close();

		if(e.type == sf::Event::Resized)
		{
			handleResize();
		}
	}
}

void GameApp::handleResize()
{
	sf::Vector2u size = window.getSize();
	if(size.x < 800)
		size.x = 800;
	if(size.y < 600)
		size.y = 600;

	if(size.x > 1920)
		size.x = 1920;
	if(size.y > 1080)
		size.y = 1080;

	window.setSize(size);
	window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y))));
}

