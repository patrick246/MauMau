#include "AIPlayer.h"
#include "MauMauMatch.h"
AIPlayer::AIPlayer(Hand* hand, MauMauMatch* m)
	:	m_ready(false)
	,	AIBase(hand, m)
{

}

bool AIPlayer::isReady() const
{
	return m_match->getApp().inputmanager.isButtonHit(sf::Mouse::Left) && (m_hand->getClickedCard() != nullptr) && isAnyCardPlayable();
}

Card* AIPlayer::playNextCard()
{
	return m_hand->getClickedCard();
}

void AIPlayer::onCardPlayed( const Card* c )
{
	
}

bool AIPlayer::isAnyCardPlayable() const
{
	Card* top = m_match->getTopCard();
	for(auto& c : *m_hand)
	{
		if(isCardPlayable(c))
			return true;
	}
	return false;
}

bool AIPlayer::isCardPlayable( Card* c ) const
{
	Card* top = m_match->getTopCard();
	if(c->value == top->value || c->color == top->color)
		return true;
	if(c->value == Card::Value::Bube)
		return true;

	return false;
}
