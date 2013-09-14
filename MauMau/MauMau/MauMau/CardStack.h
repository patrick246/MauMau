#pragma once
#include <stack>
#include "Card.h"
#include "GameApp.h"

class CardStack
	:	public sf::Drawable
	,	public sf::Transformable
{
public:
	CardStack(unsigned int totalCards, GameApp& app);

	void pushCard(Card* c);
	Card* peekCard() const;
	Card* getCard();
	void shuffle();
	
	void setTopVisible(bool v);

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	GameApp& m_app;
	std::vector<Card*> m_stack;
	bool m_isTopVisible;
	sf::Texture* m_cards_texture;
	sf::Font* m_font;
	sf::Text m_counter;
};

