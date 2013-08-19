#include "SingleplayerState.h"
#include <SFML/Graphics.hpp>
#include "GameApp.h"

SingleplayerState::SingleplayerState(GameApp& app)
	:	State(app)
	,	m_bg_tex(m_app.texturemanager.getTexture("data/shared/bg.png"))
{
}


SingleplayerState::~SingleplayerState(void)
{
}

void SingleplayerState::update( float frametime )
{
	
}

void SingleplayerState::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	sf::Sprite s(*m_bg_tex);
	target.draw(s, states);
}
