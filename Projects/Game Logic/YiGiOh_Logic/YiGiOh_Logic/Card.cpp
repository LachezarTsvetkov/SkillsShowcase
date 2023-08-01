#include"Card.hpp"

Card::Card(std::string name, std:: string effect, unsigned int rarity)
{
	this->name = name;
	this->effect = effect;
	this->rarity = rarity;
}

Card::~Card() { }

bool Card::operator<(const Card& rhs)
{
	return rarity < rhs.rarity;
}

bool Card::operator>(const Card& rhs)
{
	return rarity > rhs.rarity;
}