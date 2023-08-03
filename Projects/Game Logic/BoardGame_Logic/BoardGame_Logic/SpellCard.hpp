#include"Card.hpp"

enum class Targets {
	ENEMY = 0,
	FRIENDLY = 1,
	EVERYONE = 2,
	INVALID = 3
};

class SpellCard : protected Card
{
private:
	Targets targets;

	std::string effect;
public:
	SpellCard(std::string name = "", Rarity rarity = Rarity::INVALID, std::string description = "", unsigned int cost = 0, std::string skin = "", Targets targets = Targets::INVALID, std::string effect = "");

	Card* clone() const;

	virtual void printCardInfo();

	Targets getTargets();
	std::string getTargetsName();
	std::string getEffect();
};