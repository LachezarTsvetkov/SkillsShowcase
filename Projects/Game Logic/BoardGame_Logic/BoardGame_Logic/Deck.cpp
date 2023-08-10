#include "Deck.hpp"

Deck::Deck(std::string name) : name(name) {}

Deck::Deck(const Deck& rhs)
{
	discardDeck();
	for (auto card : rhs.cardsContainer)
	{
		cardsContainer.push_back(card->clone());
	}
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs)
	{
		discardDeck();
		for (auto card : rhs.cardsContainer)
		{
			cardsContainer.push_back(card->clone());
		}
	}
	return *this;
}


Deck::~Deck()
{
	name = "";
	for (auto card : cardsContainer)
	{
		delete card;
	}
}



__int8 Deck::getCountMonsterCards()
{
	__int8 count = 0;

	for (int i = 0; i < cardsContainer.size(); i++)
	{
		auto monster = dynamic_cast<MonsterCard*>(cardsContainer[i]);
		if (monster) 
			count++;
	}
	return count;
}

__int8 Deck::getCountSpellCards()
{
	__int8 count = 0;

	for (int i = 0; i < cardsContainer.size(); i++)
	{
		auto spell = dynamic_cast<SpellCard*>(cardsContainer[i]);
		if (spell) 
			count++;
	}
	return count;
}

__int8 Deck::getCountTotal()
{
	return cardsContainer.size();
}



void Deck::addCard(Card* card)
{
	cardsContainer.push_back(card);
}

void Deck::addCard(Card* card, __int8 index)
{
	cardsContainer.insert(cardsContainer.begin() + index, card);
}


void Deck::changeCard(Card* newCard, Card* oldCard)
{
	for (auto card : cardsContainer)
	{

	}
}

void Deck::changeCard(Card* newCard, std::string oldCardName)
{

}

void Deck::changeCard(Card* newCard, __int8 index)
{

}



void Deck::discardDeck()
{

}

void Deck::shuffleDeck()
{

}


void printDeck()
{

}


void setName(std::string name)
{

}

std::string getName()
{

}



Card* Deck::getCard(__int8 index)
{

}

Card* Deck::getCard(std::string name)
{

}


MonsterCard Deck::getCard_Monster(__int8 index)
{

}

MonsterCard Deck::getCard_Monster(std::string name)
{

}


SpellCard Deck::getCard_Spell(__int8 index)
{

}

SpellCard Deck::getCard_Spell(std::string name)
{

}