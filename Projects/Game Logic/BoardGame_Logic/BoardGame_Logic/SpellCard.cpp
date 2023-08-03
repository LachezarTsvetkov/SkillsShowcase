#include "SpellCard.hpp"

SpellCard::SpellCard(std::string name, Rarity rarity, std::string description, unsigned int cost, std::string skin, Targets targets, std::string effect) :
	Card(name, rarity, description, cost, skin), targets(targets), effect(effect) {

}

Card* SpellCard::clone() const
{
	return new SpellCard(*this);
}

void SpellCard::printCardInfo()
{
	std::cout << "Name: " + name + "\nDescription: " + description + "\nRarity: " + getRarityName() + "\nTargets: " + getTargetsName() + "\nEffect: " + effect + "\n";
}


Targets SpellCard::getTargets()
{
	return targets;
}

std::string SpellCard::getTargetsName()
{
    switch (targets) {
        case Targets::ENEMY:
            return "Enemy";
        case Targets::FRIENDLY:
            return "Friendly";
        case Targets::EVERYONE:
            return "Everyone";
        default:
            return "Invalid";
    }
}

std::string SpellCard::getEffect()
{
    return effect;
}