#include "Button.h"
#include "GameApp.h"

Button::Button( GameApp& app )
	:	m_app(app)
{
	
}

void Button::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw(m_sprite);
	target.draw(m_text);
}

void Button::update()
{
	if(m_sprite.getGlobalBounds().contains(m_app.inputmanager.getMousePos()) && m_app.inputmanager.isButtonHit(sf::Mouse::Left))
		m_handler();
}

void Button::setTexture( sf::Texture* tex )
{
	m_tex = tex;
	m_sprite.setTexture(*m_tex);
}

void Button::setFont( sf::Font* font )
{
	m_font = font;
	m_text.setFont(*m_font);
}

void Button::setText( const sf::String& str )
{
	m_text.setString(str);
}

const sf::String& Button::getText()
{
	return m_text.getString();
}

void Button::setCharacterSize( unsigned int size )
{
	m_text.setCharacterSize(size);
}

void Button::setTextColor( const sf::Color& color )
{
	m_text.setColor(color);
}

void Button::setPosition( float x, float y )
{
	setPosition(sf::Vector2f(x,y));
}

void Button::setPosition( const sf::Vector2f& pos )
{
	m_sprite.setPosition(pos);
	m_text.setPosition(pos.x + 10, pos.y + 10);
}

