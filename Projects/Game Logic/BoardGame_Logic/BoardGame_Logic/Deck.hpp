#pragma once

#include "Card.hpp"
#include "MonsterCard.hpp"
#include "SpellCard.hpp"

#include <vector>

class Deck {
private:
	std::string name;
	std::vector<Card*> cardsContainer;

public:
	Deck(std::string name = "");
	Deck(const Deck&);
	Deck& operator=(const Deck&);
	~Deck();


	__int8 getCountMonsterCards();
	__int8 getCountSpellCards();
	__int8 getCountTotal();


	void addCard(Card* card);
	void addCard(Card* card, __int8 index);

	void changeCard(Card* newCard, Card* oldCard);
	void changeCard(Card* newCard, std::string oldCardName);
	void changeCard(Card* newCard, __int8 index);


	void discardDeck();
	void shuffleDeck();

	void printDeck();

	void setName(std::string name);
	std::string getName();


	Card* getCard(__int8 index);
	Card* getCard(std::string name);

	MonsterCard getCard_Monster(__int8 index);
	MonsterCard getCard_Monster(std::string name);

	SpellCard getCard_Spell(__int8 index);
	SpellCard getCard_Spell(std::string name);

};