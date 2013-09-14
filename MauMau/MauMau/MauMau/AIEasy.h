#pragma once
#include "AIBase.h"
class AIEasy :
	public AIBase
{
public:
	AIEasy(Hand* hand, MauMauMatch* m);

	virtual bool	isReady() const;
	virtual Card*	playNextCard();
	virtual void	onCardPlayed( const Card* c );

private:
	Card* findNextCard();

};

