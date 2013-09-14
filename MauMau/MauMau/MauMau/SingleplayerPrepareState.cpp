#include "SingleplayerPrepareState.h"
#include "SingleplayerState.h"
#include <SFML/Graphics.hpp>
#include "GameApp.h"

SingleplayerPrepareState::SingleplayerPrepareState(GameApp& app)
	:	State(app)
	,	m_bg_tex(m_app.texturemanager.getResource("data/shared/bg.png"))
	,	m_start_button(app)
	,	m_cards_button_down(app)
	,	m_cards_button_up(app)
	,	m_card_count(5)
{
	m_start_button.setFont(m_app.fontmanager.getResource("data/fonts/arial.ttf"));
	m_cards_button_up.setFont(m_app.fontmanager.getResource("data/fonts/arial.ttf"));
	m_cards_button_down.setFont(m_app.fontmanager.getResource("data/fonts/arial.ttf"));

	m_cards_button_up.setTexture(m_app.texturemanager.getResource("data/SingleplayerPrepare/btn_up.png"));
	m_cards_button_down.setTexture(m_app.texturemanager.getResource("data/SingleplayerPrepare/btn_down.png"));
	m_start_button.setTexture(m_app.texturemanager.getResource("data/SingleplayerPrepare/btn_start.png"));

	m_start_button.setText("Start");

	m_cards_button_down.setPosition(225.f, 250.f);
	m_cards_button_up.setPosition(225.f, 200.f);
	m_start_button.setPosition(150.f, 350.f);

	m_card_text.setPosition(150.f, 230.f);
	m_card_text.setFont(*m_app.fontmanager.getResource("data/fonts/arial.ttf"));
	m_card_text.setString(toString(m_card_count));

	m_cards_button_down.m_handler = [&](){
		if(m_card_count > 5)
			m_card_count--;
	};

	m_cards_button_up.m_handler = [&](){
		if(m_card_count < 20)
			m_card_count++;
	};

	m_start_button.m_handler = [&](){
		SingleplayerState* sp = m_app.statemanager.getStatePtr<SingleplayerState>("SingleplayerState");
		if(sp != nullptr)
		{
			sp->setCardCount(m_card_count);
			sp->startMatch();
		} else 
		{
			throw std::runtime_error("m_start_button handler (lambda): SingleplayerState* sp is nullptr, dynamic_cast failed?");
		}
		m_app.statemanager.exchangeState("SingleplayerState");
	};
}

void SingleplayerPrepareState::update( float frametime )
{
	m_cards_button_down.update();
	m_cards_button_up.update();
	m_start_button.update();
	m_card_text.setString(toString(m_card_count));
}

void SingleplayerPrepareState::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	sf::Sprite s(*m_bg_tex);
	target.draw(s, states);
	target.draw(m_cards_button_down, states);
	target.draw(m_cards_button_up, states);
	target.draw(m_start_button, states);
	target.draw(m_card_text, states);
}
