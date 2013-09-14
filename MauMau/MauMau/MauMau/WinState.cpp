#include "WinState.h"
#include "GameApp.h"

WinState::WinState(GameApp& app)
	:	State(app)
	,	m_bg_tex(m_app.texturemanager.getResource("data/shared/bg.png"))
	,	m_font(m_app.fontmanager.getResource("data/fonts/arial.ttf"))
{
	m_text.setFont(*m_font);
	m_text.setString("You won!");
	m_text.setCharacterSize(60);
	m_text.setPosition(m_app.window.getSize().x/2.f - m_text.getGlobalBounds().width/2.f, m_app.window.getSize().y/2.f - m_text.getGlobalBounds().height/2.f);
}

void WinState::update( float frametime )
{
	m_text.setPosition(m_app.window.getSize().x/2.f - m_text.getGlobalBounds().width/2.f, m_app.window.getSize().y/2.f - m_text.getGlobalBounds().height/2.f);
}

void WinState::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw(m_text);
}
