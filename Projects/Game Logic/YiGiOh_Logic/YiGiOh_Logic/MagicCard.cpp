#include"MagicCard.hpp"

MagicCard::MagicCard(std::string name, std::string effect, unsigned int rarity, Type type):
	Card(name, effect, rarity)
{
	this->type = type;
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

std::string MagicCard::strType()
{
	if (this->type == Type::BUFF) return "BUFF";
	if (this->type == Type::SPELL) return "SPELL";
	return "TRAP";
}

void MagicCard::print()
{
	std::cout << this->name << " " << this->effect << " " << this->rarity << " " << strType() << "\n";
}