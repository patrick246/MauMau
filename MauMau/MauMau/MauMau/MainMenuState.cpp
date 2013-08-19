#include "MainMenuState.h"
#include <SFML/Graphics.hpp>
#include "GameApp.h"

#include <iostream>

MainMenuState::MainMenuState(GameApp& app)
	:	State(app)
	,	m_tex_bg(m_app.texturemanager.getTexture("data/shared/bg.png"))
	,	m_tex_button(m_app.texturemanager.getTexture("data/MainMenu/button.png"))
{
	m_tex_bg->setSmooth(true);
	m_tex_button->setSmooth(true);
	m_font.loadFromFile("data/fonts/arial.ttf");

	m_buttons.push_back(sf::Text("Singleplayer", m_font, 30));
	m_buttons[m_buttons.size()-1].setPosition(115, 100);
	m_buttons[m_buttons.size()-1].setColor(sf::Color(0,0,0));

	m_buttons.push_back(sf::Text("Multiplayer", m_font, 30));
	m_buttons[m_buttons.size()-1].setPosition(115, 200);
	m_buttons[m_buttons.size()-1].setColor(sf::Color(0,0,0));
}

void MainMenuState::update( float frametime )
{
	if(m_app.inputmanager.isButtonHit(sf::Mouse::Left))
	{
		if(m_buttons[SingleplayerButton].getGlobalBounds().contains(m_app.inputmanager.getMousePos()))
		{
			m_app.statemanager.pushState("SingleplayerState");
		}
		if(m_buttons[MultiplayerButton].getGlobalBounds().contains(m_app.inputmanager.getMousePos()))
		{
			m_app.statemanager.pushState("MultiplayerState");
		}
	}
}

void MainMenuState::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	{
		sf::Sprite bg(*m_tex_bg);
		target.draw(bg, states);
	}
	{
		for (auto it = m_buttons.begin(); it < m_buttons.end(); it++)
		{
			sf::Sprite s(*m_tex_button);
			s.setPosition(it->getPosition().x - 45, it->getPosition().y - 5);
			target.draw(s, states);
			target.draw(*it, states);
		}
	}
}
