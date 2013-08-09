#include "TextureManager.h"


TextureManager::TextureManager(void)
{
}

sf::Texture* TextureManager::getTexture( std::string filename )
{
	if(m_textures.find(filename) == m_textures.end())
	{
		m_textures[filename] = std::move(std::unique_ptr<sf::Texture>(new sf::Texture()));
		m_textures[filename]->loadFromFile(filename);
		return m_textures[filename].get();
	} else {
		return m_textures[filename].get();
	}
}

