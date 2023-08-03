#include "Card.hpp"

Card::Card(std::string name, Rarity rarity, std::string description, unsigned int cost, std::string skin): 
	name(name), rarity(rarity), description(description), cost(cost), skin(skin) {

}


bool Card::operator=(const Card& rhs)
{
	return name == rhs.name && rarity == rhs.rarity && description == rhs.description;
}

bool Card::operator<(const Card& rhs)
{
	return rarity < rhs.rarity;
}

bool Card::operator>(const Card& rhs)
{
	return rarity > rhs.rarity;
}


std::string Card::getName()
{
	return name;
}

std::string Card::getDescription()
{
	return description;
}

Rarity Card::getRarity()
{
	return rarity;
}

std::string Card::getRarityName()
{
    switch (rarity) {
        case Rarity::COMMON:
            return "Common";
        case Rarity::UNCOMMON:
            return "Uncommon";
        case Rarity::RARE:
            return "Rare";
        case Rarity::EPIC:
            return "Epic";
        case Rarity::LEGENDARY:
            return "Legendary";
        case Rarity::MYTHIC:
            return "Mythic";
        case Rarity::ASCENDED:
            return "Ascended";
        default:
            return "Invalid";
    }
}