#include "MonsterCard.hpp"

MonsterCard::MonsterCard(std::string name, Rarity rarity, std::string description, unsigned int cost, std::string skin, unsigned int attack, unsigned int defence): 
	Card(name, rarity, description, cost, skin), attack(attack), defence(defence){

}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

bool MonsterCard::operator==(const MonsterCard& rhs)
{

}

void MonsterCard::printCardInfo()
{
	std::cout << "Name: " + name + "\nDescription: " + description + "\nRarity: " + getRarityName() + "\nAttack: " + std::to_string(attack) + "\nDefence: " + std::to_string(defence) + "\n";
}


unsigned int MonsterCard::getAttack()
{
	return attack;
}

unsigned int MonsterCard::getDefence()
{
	return defence;
}


