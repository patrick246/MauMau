#include "Card.h"
#include <iostream>
Card::Card( Color c, Value v )
	:	color(c)
	,	value(v)
{
}

std::ostream& operator<<( std::ostream &os, const Card& c)
{
	std::string text;
	switch(c.color)
	{
	case Card::Color::Herz:
		text = "Herz";
		break;
	case Card::Color::Karo:
		text = "Karo";
		break;
	case Card::Color::Pik:
		text = "Pik";
		break;
	case Card::Color::Kreuz:
		text = "Kreuz";
		break;
	}
	os << text << " | ";
	text = "";
	switch (c.value)
	{
	case Card::Value::Ass:
		text = "Ass";
		break;
	case Card::Value::Bube:
		text = "Bube";
		break;
	case Card::Value::Dame:
		text = "Dame";
		break;
	case Card::Value::Koenig:
		text = "Koenig";
		break;
	case Card::Value::Ten:
		text = "Zehn";
		break;
	case Card::Value::Nine:
		text = "Neun";
		break;
	case Card::Value::Eight:
		text = "Acht";
		break;
	case Card::Value::Seven:
		text = "Sieben";
		break;
	}
	os << text << "\n\n";
	return os;
}
