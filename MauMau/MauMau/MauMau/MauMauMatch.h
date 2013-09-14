#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <memory>

#include "Hand.h"
#include "CardStack.h"
#include "AIBase.h"
#include "GameApp.h"

class MauMauMatch
	:	public sf::Drawable
{
public:
	MauMauMatch(unsigned int cardCount, GameApp& app);

	// Game methods
	void update(float frametime);

	void updateHands( float frametime );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	// MauMau methods
	/************************************************************************/
	/* Returns true if the card was successfully played, false if not       */
	/************************************************************************/
	bool playCard(Card* c);

	/************************************************************************/
	/* Returns a card from the talon                                        */
	/************************************************************************/
	Card* takeCard();

	/************************************************************************/
	/* Returns the top card from the playStack                              */
	/************************************************************************/
	Card* getTopCard();

	GameApp& getApp();

private:
	void checkForWin();
	void renewPositions();
	void AIStep( float frametime );
	void nextPlayer();

private:
	// The instance of the game app
	GameApp& m_app;

	// The amount of cards each player gets
	unsigned int m_cardCount;

	// The players
	std::array<std::unique_ptr<AIBase>, 4U> m_player;

	// The cards of the players
	std::array<std::unique_ptr<Hand>, 4U> m_hands;

	// The cards
	std::vector<std::unique_ptr<Card>> m_cards;

	// The talon, the stack where all the cards are at the beginning
	CardStack m_talon;

	// The play stack, where the cards all end up
	CardStack m_playstack;

	// The index of the current player
	unsigned int m_currentPlayer;

	// Play countdown
	float m_playCountdown;

	// Marker for the active player
	sf::CircleShape m_marker;

	enum PlayerState
	{
		FIRST_CARD,
		SECOND_CARD
	} m_playerstate;
};

