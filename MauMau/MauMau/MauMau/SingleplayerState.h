#pragma once
#include "state.h"
class SingleplayerState :
	public State
{
public:
	SingleplayerState(GameApp& app);
	~SingleplayerState(void);

	virtual void update( float frametime );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	sf::Texture* m_bg_tex;
};

