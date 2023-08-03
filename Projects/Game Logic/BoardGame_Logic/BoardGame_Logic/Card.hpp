#pragma once

#include <iostream>
#include <map>
#include <string>
enum class Rarity{
	COMMON = 0,
	UNCOMMON = 1,
	RARE = 2,
	EPIC = 3,
	LEGENDARY = 4,
	MYTHIC = 5,
	ASCENDED = 6,
	INVALID = 7
};

class Card 
{
protected:
	std::string name, description;
	Rarity rarity;
	unsigned int cost;

	std::string skin;
public:
	Card(std::string name = "", Rarity rarity = Rarity::INVALID, std::string description = "", unsigned int cost = 0, std::string skin = "");

	bool operator=(const Card& rhs);
	bool operator>(const Card& rhs);
	bool operator<(const Card& rhs);

	virtual Card* clone() const = 0;
	virtual ~Card() = 0;
	
	virtual void printCardInfo() = 0;

	std::string getName();
	std::string getDescription();
	Rarity getRarity();
	std::string getRarityName();
};