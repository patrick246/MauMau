#include "GameApp.h"


GameApp::GameApp(Config& gameConfig)
	: inputmanager(window)
	, config(gameConfig)
	, timestep(1.f / 60.f)
{
	window.create(sf::VideoMode(config.get<int>("resX"), config.get<int>("resY")), config.get<std::string>("windowtitle"), sf::Style::Titlebar | sf::Style::Close);
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
		m_accumulator -= timestep;
	}
	
	inputmanager.update();
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
			
		}
	}
}

