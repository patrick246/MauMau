#include "MauMauMatch.h"
#include "AIEasy.h"
#include "AIPlayer.h"

#include <iostream>

MauMauMatch::MauMauMatch( unsigned int cardCount, GameApp& app )
	:	m_cardCount(cardCount)
	,	m_talon(m_cardCount, app)
	,	m_currentPlayer(0)
	,	m_playstack(cardCount, app)
	,	m_app(app)
	,	m_playCountdown(0.f)
	,	m_marker(10.f)
{
	m_playstack.setTopVisible(true);

	// Allocate cards
	m_cards.reserve(128);

	for(std::size_t k = 0 ; k < 4; ++k)
	{
		for(std::size_t i = 7; i <= 14; ++i)
		{
			for(std::size_t j = 0; j < 4; ++j)
			{
				m_cards.push_back(std::unique_ptr<Card>(new Card(static_cast<Card::Color>(j), static_cast<Card::Value>(i))));
			}
		}
	}

	// Allocate Hands
	for(std::size_t i = 0; i < 4; i++)
	{
		m_hands[i] = std::unique_ptr<Hand>(new Hand(m_app));
	}
	for(std::size_t i = 0; i < 3; i++)
	{
		m_hands[i]->setVisible(false);
	}
	m_hands[3]->setVisible(true);

	// Add all cards to the talon
	for(auto& c : m_cards)
	{
		m_talon.pushCard(c.get());
	}
	
	// shuffle the talon
	m_talon.shuffle();

	// give the cards to the hands
	for(std::size_t i = 0; i < m_cardCount; ++i)
	{
		for(auto& hand : m_hands)
		{
			hand->addCard(m_talon.getCard());
		}
	}
	
	// And put one card on the playstack
	m_playstack.pushCard(m_talon.getCard());

	// Allocate players
	for (std::size_t i = 0; i < 3; i++)
	{
		m_player[i] = std::move(std::unique_ptr<AIBase>(new AIEasy(m_hands[i].get(), this)));
	}
	m_player[3] = std::move(std::unique_ptr<AIBase>(new AIPlayer(m_hands[3].get(), this)));

	// Set the properties of the marker
	m_marker.setFillColor(sf::Color::Green);
}

void MauMauMatch::update( float frametime )
{
	renewPositions();

	updateHands(frametime);


	AIStep(frametime);
	checkForWin();
}

void MauMauMatch::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	for(auto& player : m_player)
	{
		target.draw(*player->getHandPtr());
	}
	target.draw(m_talon);
	target.draw(m_playstack);

	target.draw(m_marker);
}

bool MauMauMatch::playCard( Card* c )
{
	Card* topCard = m_playstack.peekCard();
	// If the card has the value 'Bube', then it is allowed
	if(c->value == Card::Value::Bube)
	{
		m_playstack.pushCard(c);
		m_player[m_currentPlayer]->getHandPtr()->playCard(c);
		// Wrap around
		if(m_currentPlayer == 3)
		{
			m_currentPlayer = 0;
		}
		else
		{
			m_currentPlayer++;
		}
		m_playCountdown = 1.f;
		return true;

	} 
	else if(c->value == topCard->value || c->color == topCard->color)
	{
		m_playstack.pushCard(c);
		m_player[m_currentPlayer]->getHandPtr()->playCard(c);
		return true;
	}
	return false;
}

Card* MauMauMatch::takeCard()
{
	return m_talon.getCard();
}

Card* MauMauMatch::getTopCard()
{
	return m_playstack.peekCard();
}

GameApp& MauMauMatch::getApp()
{
	return m_app;
}

void MauMauMatch::AIStep( float frametime )
{
	if(m_playCountdown > 0)	// We are not ready for an AI update yet
	{
		m_playCountdown -= frametime;
		return;
	}

	if(!m_player[m_currentPlayer]->isReady())	// Player not ready for playing yet
		return;

	Card* c = m_player[m_currentPlayer]->playNextCard();
	if(c == nullptr)	// Spieler kann keine Karte legen
	{
		if(m_playerstate == FIRST_CARD)
		{
			m_player[m_currentPlayer]->getHandPtr()->addCard(m_talon.getCard());	// Er zieht eine Karte vom Stapel
			m_playerstate = SECOND_CARD;
		}
		else if(m_playerstate == SECOND_CARD)
		{
			nextPlayer();	// Wenn er nach der zweiten Karte nicht kann, dann kommt der nächste dran
		}
	} 
	else
	{
		if(!playCard(c))
		{
			throw std::runtime_error("Error invalid card");
		}
		nextPlayer();
	}
}

void MauMauMatch::renewPositions()
{
	// Position update
	m_hands[0]->setPosition(m_app.window.getSize().x/6.f*5.f - m_hands[0]->getSize().x/2.f, m_app.window.getSize().y/2.f - m_hands[0]->getSize().y/2.f);
	m_hands[2]->setPosition(m_app.window.getSize().x/6.f - m_hands[1]->getSize().x/2.f, m_app.window.getSize().y/2.f - m_hands[1]->getSize().y/2.f);
	m_hands[1]->setPosition(m_app.window.getSize().x/2.f - m_hands[2]->getSize().x/2.f, m_app.window.getSize().y/5.f - m_hands[2]->getSize().y/2.f);
	m_hands[3]->setPosition(m_app.window.getSize().x/2.f - m_hands[3]->getSize().x/2.f, (m_app.window.getSize().y/5.f)*4.f - m_hands[3]->getSize().y/2.f);

	m_marker.setPosition(m_player[m_currentPlayer]->getHandPtr()->getPosition());

	m_playstack.setPosition(m_app.window.getSize().x/2 - 125/2.f, m_app.window.getSize().y/2.f - 175/2.f);
	m_talon.setPosition(10.f, 10.f);
}

void MauMauMatch::checkForWin()
{
	// Siegesbedingung
	for(auto& player : m_player)
	{
		if(player->getHandPtr()->begin() == player->getHandPtr()->end())
		{
			if(player == m_player[3])
			{
				m_app.statemanager.exchangeState("WinState");
			}
			else
			{
				m_app.statemanager.exchangeState("LooseState");
			}
		}
	}
}

void MauMauMatch::nextPlayer()
{
	// Wrap around
	if(m_currentPlayer == 3)
	{
		m_currentPlayer = 0;
	}
	else
	{
		m_currentPlayer++;
	}
	m_playCountdown = 1.f;
	m_playerstate = FIRST_CARD;
}

void MauMauMatch::updateHands( float frametime )
{
	for(auto& hand : m_hands)
	{
		hand->update(frametime);
	}
}
