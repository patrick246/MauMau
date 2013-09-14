#include "Config.h"
#include <tinyxml2/tinyxml2.h>

Config::Config(void)
{
}

Config::Config( std::string filename )
{
	loadFromFile(filename);
}


Config::~Config(void)
{
}

void Config::loadFromFile( std::string filename )
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename.c_str());

	if(doc.Error())
		throw std::runtime_error("Config file not found or corrupt");

	for(tinyxml2::XMLNode* node = doc.FirstChildElement("configroot")->FirstChildElement("config"); node != NULL; node = node->NextSibling())
	{
		tinyxml2::XMLElement* elem = node->ToElement();
		m_config[elem->Attribute("name")] = elem->Attribute("value");
	}
}
