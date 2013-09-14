#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

/************************************************************************/
/* Template class for resource managing. Must have an default ctor and  */
/* loadFromFile method													*/
/************************************************************************/
template<class T>
class ResourceManager
	:	sf::NonCopyable
{
public:
	T* getResource(std::string filename);

private:
	std::map<std::string, std::unique_ptr<T>> m_resources;
};

template<class T>
T* ResourceManager<T>::getResource( std::string filename )
{
	if(m_resources.find(filename) == m_resources.end())
	{
		m_resources[filename] = std::move(std::unique_ptr<T>(new T()));
		if(!m_resources[filename]->loadFromFile(filename))
		{
			throw std::runtime_error(std::string("ResourceManager for ") + typeid(T).name() + ": Cannot load file \"" + filename + "\"");
		}
		return m_resources[filename].get();
	}
	else
	{
		return m_resources[filename].get();
	}
}

typedef ResourceManager<sf::Texture>	TextureManager;
typedef ResourceManager<sf::Font>		FontManager;