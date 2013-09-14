#pragma once
#include "state.h"
class WinState :
	public State
{
public:
	WinState(GameApp& app);

	virtual void update( float frametime );
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	sf::Texture*	m_bg_tex;
	sf::Text		m_text;
	sf::Font*		m_font;

};

