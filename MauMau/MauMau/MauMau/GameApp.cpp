#include "GameApp.h"


GameApp::GameApp()
	: input(window)
{
	window.create(sf::VideoMode(1024,768), "Mau Mau", sf::Style::Titlebar | sf::Style::Close);
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

	input.update();
}

void GameApp::render()
{
	window.clear();
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
			window.setSize(sf::Vector2u(800,600));
		}
	}
}

