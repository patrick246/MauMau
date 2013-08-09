#pragma once
#include <string>
#include <map>
#include "util.h"

class Config
{
public:
	Config(void);
	Config(std::string filename);
	~Config(void);

	void loadFromFile(std::string filename);

	template<typename T>
	T get(const std::string& key) const;
private:
	typedef std::map<std::string, std::string> configmap;
	configmap m_config;
};

template<typename T>
T Config::get(const std::string& key) const
{
	configmap::const_iterator it = m_config.find(key);
	if(it == m_config.end())
		return strTo<T>("");

	return strTo<T>(it->second);
}

