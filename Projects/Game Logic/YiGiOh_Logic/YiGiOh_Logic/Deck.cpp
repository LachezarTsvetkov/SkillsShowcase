#include<cstdlib>
//Those libraries are for the random shuffle of the deck
#include <algorithm>
#include <random>

#include"Deck.hpp"

Deck::Deck(std::string name) :name(name) {}

Deck::Deck(const Deck& rhs)
{
	clearDeck();
	for (auto x : rhs.cardContainer)
	{
		cardContainer.push_back(x->clone());
	}
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs)
	{
		clearDeck();
		for (auto x : rhs.cardContainer)
		{
			cardContainer.push_back(x->clone());
		}
	}
	return *this;
}

Deck::~Deck()
{
	for (auto x : cardContainer)
	{
		delete x;
	}
}

int Deck::getMonsterCards()
{
	int cardCount = 0;
	for (int i = 0; i < cardContainer.size(); i++)
	{
		//Using dynamic cast to check whether the card with index 'i' is a MonsterCard, and if yes - increase the counter
		auto monster = dynamic_cast<MonsterCard*>(cardContainer[i]);
		if (monster) cardCount++;
	}
	return cardCount;
}

int Deck::getMagicCards()
{
	int cardCount = 0;
	for (int i = 0; i < cardContainer.size(); i++)
	{
		//Same as the function above
		auto magic = dynamic_cast<MagicCard*>(cardContainer[i]);
		if (magic) cardCount++;
	}
	return cardCount;
}

int Deck::getPendulumCards()
{
	int cardCount = 0;
	for (int i = 0; i < cardContainer.size(); i++)
	{
		//Same as the function above
		auto pendulum = dynamic_cast<PendulumCard*>(cardContainer[i]);
		if (pendulum) cardCount++;
	}
	return cardCount;
}

int Deck::getTotalCards()
{
	return cardContainer.size();
}

void Deck::addCard(Card* card)
{
	cardContainer.push_back(card);
}

void Deck::changeCard(Card* card, size_t index)
{
	//First checks whether a card with such index exists, and if no - throws error
	if (index > cardContainer.size() - 1)
	{
		std::cout << "No MonsterCard with such index exists\n";
		return;
	}

	//Kinda badly written, but meh:
	//For every type of card, creates 2 temporary variables to check whether the card at posistion 'index' is the same type as the one called for
	auto checkMonster1 = dynamic_cast<MonsterCard*>(cardContainer[index]);
	auto checkMonster2 = dynamic_cast<MonsterCard*>(card);
	if (checkMonster1 && checkMonster2)
	{
		delete[] cardContainer[index];
		cardContainer[index] = card->clone();
		return;
	}

	auto checkMagic1 = dynamic_cast<MonsterCard*>(cardContainer[index]);
	auto checkMagic2 = dynamic_cast<MonsterCard*>(card);
	if (checkMagic1 && checkMagic2)
	{
		delete[] cardContainer[index];
		cardContainer[index] = card->clone();
		return;
	}

	auto checkPendulum1 = dynamic_cast<MonsterCard*>(cardContainer[index]);
	auto checkPendulum2 = dynamic_cast<MonsterCard*>(card);
	if (checkPendulum1 && checkPendulum2)
	{
		delete[] cardContainer[index];
		cardContainer[index] = card->clone();
		return;
	}
	std::cout << "The card with this index doesn't match the type of the thrown card\n";

}

void Deck::clearDeck()
{
	for (int i = 0; i < cardContainer.size(); i++)
	{
		delete[] cardContainer[i];
	}
	cardContainer.clear();
}

void Deck::scrambleDeck()
{
	//Magic
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(cardContainer), std::end(cardContainer), rng);
}

void Deck::printDeck()
{
	//Prints the deck with some space before each card
	std::cout << "\nDeck Name: " << name<<"\n Cards:";
	for (int i = 0; i < cardContainer.size(); i++)
	{
		std::cout << "\n     ";
		cardContainer[i]->print();
	}
	std::cout << "\n";
}

void Deck::setName(std::string name)
{
	this->name = name;
}

std::string Deck::getName()
{
	return this->name;
}

Card* Deck::getCard(int index)
{
	return cardContainer[index];
}

MonsterCard Deck::getMonster(int index)
{
	int count = 0;
	MonsterCard tempMonster;
	for (int i = 0; i < cardContainer.size(); i++)
	{
		//When needing the 'index' amount MonsterCard finding it and returning it (used in the file saving)
		auto x = dynamic_cast<MonsterCard*>(cardContainer[i]);
		if (x)
		{
			if (count == index)
			{
				tempMonster = *x;
				break;
			}
			count++;
		}
	}
	std::cout << "No MonsterCard with such index exists\n";
	return tempMonster;
}

MagicCard Deck::getMagic(int index)
{
	int count = 0;
	MagicCard tempMagic;
	for (int i = 0; i < cardContainer.size(); i++)
	{
		auto x = dynamic_cast<MagicCard*>(cardContainer[i]);
		if (x)
		{
			if (count == index) tempMagic = *x;
			count++;
		}
	}
	std::cout << "No MagicCard with such index exists\n";
	return tempMagic;
}

PendulumCard Deck::getPendulum(int index)
{
	int count = 0;
	PendulumCard tempPendulum;
	for (int i = 0; i < cardContainer.size(); i++)
	{
		auto x = dynamic_cast<PendulumCard*>(cardContainer[i]);
		if (x)
		{
			if (count == index) tempPendulum = *x;
			count++;
		}
	}
	return tempPendulum;
}