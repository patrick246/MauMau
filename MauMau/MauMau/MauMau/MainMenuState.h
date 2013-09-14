#pragma once
#include "state.h"
class MainMenuState :
	public State
{
public:
	MainMenuState(GameApp& app);

	virtual void update( float frametime );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
private:
	sf::Texture* m_tex_bg;
	sf::Texture* m_tex_button;

	sf::Font* m_font;

	std::vector<sf::Text> m_buttons;

	enum Buttons
	{
		SingleplayerButton = 0,
		MultiplayerButton,
		OptionsButton
	};
};

