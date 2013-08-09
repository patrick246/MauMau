#pragma once

#include <vector>
#include <memory>

#include "Hand.h"

class CardManager
{
public:
	CardManager(int playercount);
	Hand getMyHand();
	void fillTalon();

private:
	int m_playercount;
	std::vector<std::unique_ptr<Card>> m_cards;
};

