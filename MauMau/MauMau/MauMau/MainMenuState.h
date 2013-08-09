#pragma once
#include "state.h"
class MainMenuState :
	public State
{
public:
	MainMenuState(GameApp& app);

	virtual void update( float frametime );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

};

