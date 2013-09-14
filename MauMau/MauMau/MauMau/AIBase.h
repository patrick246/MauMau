#pragma once
#include "Hand.h"
class MauMauMatch;

class AIBase
{
public:
	AIBase(Hand* hand, MauMauMatch* m)
		:	m_hand(hand)
		,	m_match(m)
	{
	}

	virtual bool	isReady() const = 0;
	virtual Card*	playNextCard() = 0;
	virtual void	onCardPlayed(const Card* c) = 0;
	inline Hand*	getHandPtr();

	virtual void	update(){};
protected:
	Hand*			m_hand;
	MauMauMatch*	m_match;
};

inline Hand* AIBase::getHandPtr()
{
	return m_hand;
}

