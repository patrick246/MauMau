#pragma once
#include <SFML/Graphics.hpp>

class State
	:	sf::Drawable
{
	// Virtual method for updating the state
	virtual void update(float frametime) {}

	// Virtual method for displaying the state
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {}
};