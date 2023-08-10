#include"Card.hpp"

class MonsterCard : protected Card
{
private:
	unsigned int attack, defence;

public:
	MonsterCard(std::string name = "", Rarity rarity = Rarity::INVALID, std::string description = "", unsigned int cost = 0, std::string skin = "", unsigned int attack = 0, unsigned int defence = 0);

	Card* clone() const;

	bool operator==(const MonsterCard& rhs);

	virtual void printCardInfo();

	unsigned int getAttack();
	unsigned int getDefence();
};