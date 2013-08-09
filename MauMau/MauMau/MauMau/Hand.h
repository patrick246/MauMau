#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:
	Hand(void);

private:
	std::vector<Card*> m_cards;
};

