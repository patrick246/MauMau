#include "CardStack.h"
#include <random>

CardStack::CardStack(unsigned int totalCards, GameApp& app)
	:	m_isTopVisible(false)
	,	m_cards_texture(m_app.texturemanager.getResource("data/cards/cards_all.png"))
	,	m_app(app)
	,	m_font(m_app.fontmanager.getResource("data/fonts/arial.ttf"))
{
}

void CardStack::pushCard( Card* c )
{
	m_stack.push_back(c);
}

Card* CardStack::peekCard() const
{
	if(m_stack.size() == 0)
		throw std::runtime_error("CardStack::peekCard(): stack size is zero");

	return m_stack.back();
}

Card* CardStack::getCard()
{
	if(m_stack.size() == 0)
		throw std::runtime_error("CardStack::getCard(): stack size is zero");

	Card* temp = m_stack.back();
	m_stack.pop_back();
	return temp;
}

void CardStack::shuffle()
{
	std::random_shuffle(m_stack.begin(), m_stack.end());
}

void CardStack::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	sf::Sprite s(*m_cards_texture);
	if(m_stack.size() > 0)
	{
		auto c = peekCard();
		if(!m_isTopVisible)
		{
			s.setTextureRect(sf::IntRect(0, 700, 125, 174));
		}
		else if (c->value == Card::Value::Ass)
		{
			s.setTextureRect(sf::IntRect(0, static_cast<int>(c->color)*175, 125, 175));
		}
		else
		{
			s.setTextureRect(sf::IntRect((static_cast<int>(c->value)-1)*125, static_cast<int>(c->color)*175, 125, 175));
		}
	} 
	else 
	{
		s.setTextureRect(sf::IntRect(250, 700, 125, 174));
	}
	s.setPosition(0.f,0.f);
	states.transform *= getTransform();
	target.draw(s, states);
}

void CardStack::setTopVisible( bool v )
{
	m_isTopVisible = v;
}
