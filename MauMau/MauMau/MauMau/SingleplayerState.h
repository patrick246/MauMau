#pragma once
#include <memory>
#include "state.h"
#include "MauMauMatch.h"
class SingleplayerState :
	public State
{
public:
	SingleplayerState(GameApp& app);

	virtual void update( float frametime );
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	void setCardCount(unsigned int cardCount);
	void startMatch();

private:
	unsigned int m_cardCount;
	bool m_matchStarted;
	std::unique_ptr<MauMauMatch> m_match;
	sf::Texture* m_bg_tex;
};

