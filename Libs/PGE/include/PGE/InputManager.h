#pragma once

// added by patrick246
#ifdef _DEBUG
#pragma comment(lib, "InputManager-d.lib")
#else
#pragma comment(lib, "InputManager.lib")
#endif


#include <SFML/Graphics.hpp>
#include <map>
namespace pge
{
	class InputManager
	{
	public:
		InputManager(sf::RenderWindow& w);
		~InputManager(void);
		void update();

		// Keyboard
		bool isKeyPressed(sf::Keyboard::Key key) const;
		bool isKeyHit(sf::Keyboard::Key key) const;

		// Mouse
		sf::Vector2f getMousePos() const;
		bool isButtonPressed(sf::Mouse::Button button) const;
		bool isButtonHit(sf::Mouse::Button button) const;

	private:
		std::map<sf::Keyboard::Key, bool> m_keys_pressed;
		std::map<sf::Keyboard::Key, bool> m_prev_keys_pressed;

		std::map<sf::Mouse::Button, bool> m_mouse_pressed;
		std::map<sf::Mouse::Button, bool> m_mouse_prev_pressed;

		sf::RenderWindow& m_window;
	};
}