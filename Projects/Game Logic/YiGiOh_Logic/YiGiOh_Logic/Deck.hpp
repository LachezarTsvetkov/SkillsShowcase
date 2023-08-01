#pragma once

#include<vector>

#include"Card.hpp"
#include"MonsterCard.hpp"
#include"MagicCard.hpp"
#include"PendulumCard.hpp"

class Deck 
{
private:
	std::string name;
	std::vector<Card*> cardContainer;
public:
	//Big 4
	Deck(std::string name = ""); 
	Deck(const Deck&);
	Deck& operator=(const Deck&);
	~Deck();

	//Functions to return the number of specific/total cards in the deck
	int getMonsterCards();
	int getMagicCards();
	int getPendulumCards();
	int getTotalCards();

	//Functions to add/change cards
	void addCard(Card* card);
	void changeCard(Card* card, size_t index);

	void clearDeck();
	void scrambleDeck();
	
	void printDeck();

	void setName(std::string name);
	std::string getName();

	//Function to return a card with specific index from the cardContainer (made this so that cardContainer doesn't need to become public)
	Card* getCard(int index);

	MonsterCard getMonster(int index);
	MagicCard getMagic(int index);
	PendulumCard getPendulum(int index);
};