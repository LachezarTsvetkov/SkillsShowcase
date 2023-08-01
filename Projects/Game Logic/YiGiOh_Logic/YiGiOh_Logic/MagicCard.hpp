#pragma once

#include<iostream>
#include"Card.hpp"

enum class Type {
	TRAP = 0,
	BUFF = 1,
	SPELL = 2,
	Invalid = 3, //Invalid for the default values
};
//This class inherits 'Card' in order to gain acces to 'name' and 'effect'
class MagicCard :virtual public Card
{
public:
	Type type;

	//Constructor with variables + default values
	MagicCard(std::string name = "", std::string effect = "", unsigned int rarity = 0, Type type = Type::Invalid);

	Card* clone() const;

	//strType is used for easier printing/reading of the type
	std::string strType();
	//print - displays the information about this specific card
	virtual void print();
};