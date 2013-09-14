#include "AIEasy.h"
#include "MauMauMatch.h"

AIEasy::AIEasy(Hand* hand, MauMauMatch* m)
	:	AIBase(hand, m)
{
}

bool AIEasy::isReady() const
{
	return true;
}

Card* AIEasy::playNextCard()
{
	return findNextCard();
}

void AIEasy::onCardPlayed( const Card* c )
{
	
}

Card* AIEasy::findNextCard()
{
	Card* topCard = m_match->getTopCard();
	for(Card* c : *m_hand)
	{
		if(c->color == topCard->color || c->value == topCard->value)
		{
			return c;
		}
	}
	return nullptr;
}

