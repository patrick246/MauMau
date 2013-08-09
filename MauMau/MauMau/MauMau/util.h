#pragma once
#include <sstream>
#include <string>

template<typename T>
inline std::string toString(T in)
{
	std::stringstream s;
	s << in;
	return s.str();
}

template<>
inline std::string toString(std::string in)
{
	return in;
}

template<typename T>
inline T strTo(std::string in)
{
	T temp;
	std::stringstream s;
	s << std::boolalpha << in;
	s >> temp;
	return temp;
}

template<>
inline std::string strTo(std::string in)
{
	return in;
}

template <class Map> 
typename Map::mapped_type map_find(Map &map, const typename Map::key_type &key) 
{ 
	typename Map::const_iterator it = map.find(key); 
	return (it != map.end()) ? it->second : Map::mapped_type(); 
}
