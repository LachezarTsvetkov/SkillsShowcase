#include"PendulumCard.hpp"

PendulumCard::PendulumCard(std::string name, std::string effect, unsigned int rarity, unsigned int attackPoints, unsigned int defensePoints, unsigned int pendulumScale, Type type)
    :MonsterCard(name, effect, rarity, attackPoints, defensePoints),
     MagicCard(name, effect, rarity, type) {
        this->pendulumScale = pendulumScale;
}

Card* PendulumCard::clone() const
{
    return new MonsterCard(*this);
}

void PendulumCard::print()
{
	std::cout << this->name << " " << this->effect << " " << this->attackPoints << " " << this->defensePoints << " " << this->pendulumScale << " " << strType() << "\n";
}