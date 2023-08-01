#pragma once

#include<iostream>
#include"Card.hpp"

//This class inherits 'Card' in order to gain acces to 'name' and 'effect'
class MonsterCard : virtual public Card
{
public:
	unsigned int attackPoints, defensePoints;

	//Constructor with variables + default values
	MonsterCard(std::string name = "", std::string effect = "", unsigned int rarity = 0, unsigned int attackPoints = 0, unsigned int defensePoints = 0);

	//Function for creating/accessing cards
	Card* clone() const;

	//print - displays the information about this specific card
	virtual void print();
};