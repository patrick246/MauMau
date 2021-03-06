#pragma once
#include <SFML/Graphics.hpp>

class GameApp;
class State
	:	sf::Drawable
{
public:
	State(GameApp& app) 
		:	m_app(app)
	{}

	// Virtual method for updating the state
	virtual void update(float frametime) {}

	// Virtual method for displaying the state
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {}

protected:
	GameApp& m_app;
};