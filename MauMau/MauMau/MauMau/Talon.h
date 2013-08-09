#pragma once
#include <stack>

#include "Card.h"

class Talon
{
public:
	Talon(void);
	void addCard(Card* card);
	Card* takeCard();

private:
	std::stack<Card*> m_cardstack;
};

