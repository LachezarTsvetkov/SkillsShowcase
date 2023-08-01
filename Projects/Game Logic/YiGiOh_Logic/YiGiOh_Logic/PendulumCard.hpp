#pragma once

#include<iostream>
#include"MonsterCard.hpp"
#include"MagicCard.hpp"

//This class inherits 'MonsterCard' and 'MagicCard' in order to gain acces to their : 'name' , 'effect' , 'attackPoints' , 'defensePoints' , and 'type'
class PendulumCard : public MonsterCard, public MagicCard 
{
public:
	//Variable that stores the custom number of the card
	int pendulumScale;
	
	PendulumCard(std::string name = "", std::string effect = "", unsigned int rarity = 0, unsigned int attackPoints = 0, unsigned int defensePoints = 0, unsigned int pendulumNumber = 0, Type type = Type::Invalid);
	
	Card* clone() const;

	//print - displays the information about this specific card
	virtual void print();
};