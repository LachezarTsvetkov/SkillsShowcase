#include"MonsterCard.hpp"

MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int rarity, unsigned int attackPoints, unsigned int defensePoints):
	Card(name, effect, rarity)
{
	this->attackPoints = attackPoints;
	this->defensePoints = defensePoints;
}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

void MonsterCard::print()
{
	std::cout << this->name << " " << this->effect << " " << this->rarity << " " << this->attackPoints << " " << this->defensePoints << "\n";
}