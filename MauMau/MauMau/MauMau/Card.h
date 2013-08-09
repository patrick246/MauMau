#pragma once
class Card
{
public:
	enum Color
	{
		Clubs,		// Kreuz
		Diamons,	// Karo
		Spades,		// Pik
		Hearts		// Herz
	};

	enum Value
	{
		Two = 2,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};
private:
	Color color;
	Value value;
public:
	Card(Color c, Value v);

	Color getColor();
	Value getValue();

};

