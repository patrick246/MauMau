#include "Card.h"


Card::Card( Color c, Value v )
	:	color(c)
	,	value(v)
{
}

Card::Color Card::getColor()
{
	return color;
}

Card::Value Card::getValue()
{
	return value;
}
