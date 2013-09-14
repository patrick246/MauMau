#pragma once
#include "AIBase.h"
class AIPlayer
	:	public AIBase
{
public:
	AIPlayer(Hand* hand, MauMauMatch* m);

	virtual bool isReady() const;
	virtual Card* playNextCard();
	virtual void onCardPlayed( const Card* c );

	bool isCardPlayable(Card* c) const;
	bool isAnyCardPlayable() const;

private:
	bool m_ready;
};

