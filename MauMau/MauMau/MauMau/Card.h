#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
struct Card
	:	sf::NonCopyable
{
	enum class Color
	{
		Kreuz,
		Herz,
		Pik,
		Karo
	} const color;

	enum class Value
	{
		Seven = 7,
		Eight,
		Nine,
		Ten,
		Bube,
		Dame,
		Koenig,
		Ass
	} const value;

	Card(Color c, Value v);
};

std::ostream& operator<< (std::ostream &os, const Card&);