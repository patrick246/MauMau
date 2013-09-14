#pragma once
#include <vector>

#include "Card.h"
#include "GameApp.h"

class Hand
	:	public sf::Drawable
	,	public sf::Transformable
{
public:
	Hand(GameApp& app);
	std::vector<Card*>::iterator begin();
	std::vector<Card*>::iterator end();
	std::vector<Card*>::const_iterator begin() const;
	std::vector<Card*>::const_iterator end() const;

	void addCard(Card* c); 
	void playCard(Card* c);

	void setVisible(bool v);

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	void update(float frametime);

	sf::Vector2f getSize() const;

	Card* getClickedCard() const;
private:
	std::vector<Card*> m_cards;
	sf::Texture* m_cards_texture;
	bool m_visible;

	Card* m_clickedCard;
	GameApp& m_app;
};

