#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
class GameApp;

class Button
	:	public sf::Drawable
{
public:
	Button(GameApp& app);

	void update();
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	void setTexture(sf::Texture* tex);
	void setFont(sf::Font* font);
	void setText(const sf::String& str);
	const sf::String& getText();
	void setCharacterSize(unsigned int size);
	void setTextColor(const sf::Color& color);
	void setPosition(const sf::Vector2f& pos);
	void setPosition(float x, float y);

public:
	std::function<void()> m_handler;
	
private:
	sf::Texture* m_tex;
	sf::Font*	 m_font;
	sf::Text	 m_text;
	sf::Sprite	 m_sprite;
	GameApp& m_app;

public:

};