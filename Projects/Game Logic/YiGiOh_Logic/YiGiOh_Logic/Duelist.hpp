#pragma once
#include<iostream>

#include"Deck.hpp"


class Duelist
{
private:
	std::string name;
	Deck deck;
public:
	Duelist(std::string name = ""); 

	//Function to allow acces to the Deck class
	Deck& getDeck();
	
	//Functions that save and read information to/from a targeted file
	bool saveFile(std::string fileName);
	bool readFile(std::string fileName);

	//Fucntion for players to fight
	void duel(Duelist& player2);

	
	void setDeck(Deck deck);
	void setName(std::string name);
};