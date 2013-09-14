#pragma once
#include "state.h"
#include <functional>
#include "Button.h"

class SingleplayerPrepareState :
	public State
{
public:
	SingleplayerPrepareState(GameApp& app);

	virtual void update( float frametime );
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	sf::Texture* m_bg_tex;

	Button m_start_button;
	Button m_cards_button_up;
	Button m_cards_button_down;
	sf::Text m_card_text;

	int m_card_count;
};

