#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager(void);
	sf::Texture* getTexture(std::string filename);

private:
	std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
};

