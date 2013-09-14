#include "SingleplayerState.h"


SingleplayerState::SingleplayerState(GameApp& app)
	:	State(app)
	,	m_cardCount(0)
	,	m_matchStarted(false)
	,	m_bg_tex(m_app.texturemanager.getResource("data/shared/bg.png"))
{
}

void SingleplayerState::update( float frametime )
{
	if(m_cardCount == 0)
		throw std::runtime_error("SingleplayerState::update(): card count is zero, should be set from SingleplayerPrepareState");

	if(m_match.get() == nullptr)
		throw std::runtime_error("SingleplayerState::update(): match is not initialised, cannot draw anything");

	m_match->update(frametime);
}

void SingleplayerState::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if(m_cardCount == 0)
		throw std::runtime_error("SingleplayerState::draw(): card count is zero, should be set from SingleplayerPrepareState");

	if(m_match.get() == nullptr)
		throw std::runtime_error("SingleplayerState::draw(): match is not initialised, cannot draw anything");
	
	target.draw(sf::Sprite(*m_bg_tex));
	target.draw(*m_match, states);
}

void SingleplayerState::setCardCount( unsigned int cardCount )
{
	m_cardCount = cardCount;
}

void SingleplayerState::startMatch()
{
	m_matchStarted = true;
	m_match = std::move(std::unique_ptr<MauMauMatch>(new MauMauMatch(m_cardCount, m_app)));
}
