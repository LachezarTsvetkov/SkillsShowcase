#pragma once

#include<iostream>

//Card is a parent class for MonsterCard and MagicCard, since they share the indentical properties of having 'name' and 'effect'
class Card
{
public:
	//All is public so that they can be accessed later more easly, without requiring getters and setters
	std::string name, effect;
	unsigned int rarity;

	Card(std::string name = "", std::string effect = "", unsigned int rarity = 0);

	//Operators for comparing cards
	bool operator>(const Card& rhs);
	bool operator<(const Card& rhs);

	
	virtual Card* clone() const = 0;
	virtual ~Card() = 0;

	//Virtual function 'print' that would be used by other classes
	virtual void print() = 0;
};