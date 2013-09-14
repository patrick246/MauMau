#include "Hand.h"
#include "util.h"

#include "SingleplayerState.h"

Hand::Hand(GameApp& app)
	:	m_cards_texture(app.texturemanager.getResource("data/cards/cards_all.png"))
	,	m_visible(false)
	,	m_app(app)
	,	m_clickedCard(nullptr)
{
}

std::vector<Card*>::iterator Hand::begin()
{
	return m_cards.begin();
}

std::vector<Card*>::const_iterator Hand::begin() const
{
	return m_cards.cbegin();
}

std::vector<Card*>::iterator Hand::end()
{
	return m_cards.end();
}

std::vector<Card*>::const_iterator Hand::end() const
{
	return m_cards.cend();
}

void Hand::addCard( Card* c )
{
	m_cards.push_back(c);
}

void Hand::playCard( Card* c )
{
	auto it = std::find(begin(), end(), c);
	if(it == end())
		throw std::runtime_error(std::string("Hand::playCard(): Card not present: ") + toString(static_cast<int>(c->value)) + " " + toString(static_cast<int>(c->color)));
	m_cards.erase(it);
}

void Hand::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	int i = 0;
	states.transform *= getTransform();
	for(Card* c : *this)
	{
		sf::Sprite s(*m_cards_texture);
		if(!m_visible)
		{
			s.setTextureRect(sf::IntRect(0, 700, 125, 174));
		}
		else if(c->value == Card::Value::Ass)
		{
			s.setTextureRect(sf::IntRect(0, static_cast<int>(c->color)*175, 125, 175));
		} else {
			s.setTextureRect(sf::IntRect((static_cast<int>(c->value)-1)*125, static_cast<int>(c->color)*175, 125, 175));
		}
		s.setPosition(i*20.f,0.f);
		target.draw(s, states);
		++i;
	}
}

sf::Vector2f Hand::getSize() const
{
	float x = 0;
	for(auto& c : m_cards)
	{
		x += 20;
	}
	x += 105;
	return sf::Vector2f(x, 175.f);
}

void Hand::setVisible( bool v )
{
	m_visible = v;
}

void Hand::update( float frametime )
{
	if(!m_visible)
		return;

	int i = 0;
	m_clickedCard = nullptr;
	for(auto c : *this)
	{
		sf::FloatRect rect(getPosition().x + i * 20.f, getPosition().y, 20.f, 174.f);
		if(m_app.inputmanager.isButtonHit(sf::Mouse::Left) && rect.contains(m_app.inputmanager.getMousePos()))
		{
			m_clickedCard = c;
		}
		i++;
	}
	sf::FloatRect rect(getPosition().x + (m_cards.size()-1) * 20.f, getPosition().y, 125.f, 174.f);
	if(m_app.inputmanager.isButtonHit(sf::Mouse::Left) && rect.contains(m_app.inputmanager.getMousePos()))
	{
		m_clickedCard = *(end()-1);
	}
}

Card* Hand::getClickedCard() const
{
	return m_clickedCard;
}


