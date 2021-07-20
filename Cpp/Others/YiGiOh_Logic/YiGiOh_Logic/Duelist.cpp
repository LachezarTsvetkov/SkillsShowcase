#include<fstream>
#include<string>

#include<iostream>
#include"Duelist.hpp"

Duelist::Duelist(std::string name)
{
	this->name = name;
}

Deck& Duelist::getDeck()
{
	return deck;
}

void Duelist::setDeck(Deck deck)
{
	this->deck = deck;
}

bool Duelist::saveFile(std::string fileName)
{
	std::fstream myFile;
	myFile.open(fileName, std::ios::out);
	if (!myFile)//If the file doesn't open, throw error
	{
		std::cout << "Error! File could not be opened / created";
		myFile.close();
		return false;
	}
	else
	{
		//Writes the first line to the txt file
		myFile << getDeck().getName() << "|" << getDeck().getMonsterCards() << "|" << getDeck().getMagicCards() << "|" << getDeck().getPendulumCards() << "\n";
		
		//For each MonsterCard that the deck contains, store it in the file
		for(int i = 0; i < getDeck().getMonsterCards(); i++)
		{
			myFile << getDeck().getMonster(i).name << "|" << getDeck().getMonster(i).effect << "|" << getDeck().getMonster(i).rarity << "|" << getDeck().getMonster(i).attackPoints << "|" << getDeck().getMonster(i).defensePoints << "\n";
		}

		//For each MagicCard that the deck contains, store it in the file
		for(int i = 0; i < getDeck().getMagicCards(); i++)
		{
			myFile << getDeck().getMagic(i).name << "|" << getDeck().getMagic(i).effect << "|" << getDeck().getMagic(i).rarity << "|" << getDeck().getMagic(i).strType() << "\n" ;
		}

		//For each PendulumCard that the deck contains, store it in the file
		for(int i = 0; i < getDeck().getPendulumCards(); i++)
		{
			myFile << getDeck().getPendulum(i).name << "|" << getDeck().getPendulum(i).effect << "|" << getDeck().getPendulum(i).rarity << "|" << getDeck().getPendulum(i).attackPoints << "|";
			myFile << getDeck().getPendulum(i).defensePoints << "|" << getDeck().getPendulum(i).pendulumScale << "|" << getDeck().getPendulum(i).strType() << "\n";
		}
		myFile.close();
		return true;
	}
}

bool Duelist::readFile(std::string fileName)
{
	std::fstream myFile;
	myFile.open(fileName, std::ios::in);
	if (!myFile)//If such file doesn't exists, or can't be opened, throw error
	{
		std::cout << "No such file exists / can't be opened\n";
		myFile.close();
		return false;
	}
	else
	{
		//Cleares the current deck
		getDeck().clearDeck();
		std::string line;
		//The first thing it reads is the the name of the deck, and then renames the deck itself
		std::getline(myFile, line, '|');
		deck.setName(line);

		//Reads the ammount of Monster,Magic and Pendulum cards
		std::getline(myFile, line, '|');
		int monsterCount = stoi(line);
		std::getline(myFile, line, '|');
		int magicCount = stoi(line);
		std::getline(myFile, line);
		int pendulumCount = stoi(line);

		//For each Monster card:
		for (int i = 0; i < monsterCount; i++)
		{
			//Reads and stores the name, effect, rarity, attackPoints and defensePoints
			std::getline(myFile, line, '|');
			std::string monName = line;

			std::getline(myFile, line, '|');
			std::string monEffect = line;

			std::getline(myFile, line, '|');
			unsigned int monRarity = stoi(line);

			std::getline(myFile, line, '|');
			int monAP = std::stoi(line);

			std::getline(myFile, line);
			int monDP = std::stoi(line);

			//Creates a temporary MonsterCard and includes it in the container/vector
			deck.addCard(new MonsterCard (monName, monEffect, monRarity, monAP, monDP));
		}
		//Same goes for the Magic and Pendulum cards
		for (int i = 0; i < magicCount; i++)
		{
			std::getline(myFile, line, '|');
			std::string magName = line;

			std::getline(myFile, line, '|');
			std::string magEffect = line;

			std::getline(myFile, line, '|');
			unsigned int magRarity = stoi(line);

			std::getline(myFile, line);
			Type type;
			if (line == "BUFF") type = Type::BUFF;
			else if (line == "SPELL") type = Type::SPELL;
			else type = Type::TRAP;

			deck.addCard(new MagicCard (magName, magEffect, magRarity, type));
		}
		for (int i = 0; i < pendulumCount; i++)
		{
			std::getline(myFile, line, '|');
			std::string penName = line;

			std::getline(myFile, line, '|');
			std::string penEffect = line;

			std::getline(myFile, line, '|');
			unsigned int penRarity = stoi(line);

			std::getline(myFile, line, '|');
			int penAP = stoi(line);

			std::getline(myFile, line, '|');
			int penDP = stoi(line);

			std::getline(myFile, line, '|');
			int penS = stoi(line);

			std::getline(myFile, line);
			Type type;
			if (line == "BUFF") type = Type::BUFF;
			else if (line == "SPELL") type = Type::SPELL;
			else type = Type::TRAP;

			deck.addCard(new PendulumCard (penName, penEffect, penRarity, penAP, penDP, penS, type));
		}
		
		myFile.close();
		return true;
	}
}
void Duelist::duel(Duelist& player2)
{
	//Shuffeling player2's deck twice in order to change the 'seed' called
	this->getDeck().scrambleDeck();
	player2.getDeck().scrambleDeck();
	player2.getDeck().scrambleDeck();
	player2.getDeck().scrambleDeck();

	//If there are 0 cards || the amount of cards in both decks isn't the same
	if (this->getDeck().getTotalCards() != player2.getDeck().getTotalCards() || this->getDeck().getTotalCards() == 0 || player2.getDeck().getTotalCards() == 0)
	{
		std::cout << "No match is possible due to insufficient number of cards exisiting in both player's decks\n";
		return;
	}

	//Variables to save the score
	int scoreP1 = 0, scoreP2 = 0;

	//Increasing the score
	for (int i = 0; i < this->getDeck().getTotalCards(); i++)
	{
		if (this->getDeck().getCard(i)->rarity > player2.getDeck().getCard(i)->rarity) scoreP1++;
		else if (this->getDeck().getCard(i)->rarity < player2.getDeck().getCard(i)->rarity) scoreP2++;
	}

	//Printing ths core and the aftermath
	std::cout << scoreP1 << " : " << scoreP2 <<"\n";
	if (scoreP1 > scoreP2) std::cout << "Player 1 '" << this->name << "' wins the match against Player 2 '" << player2.name << "'\n";
	else if (scoreP1 < scoreP2) std::cout << "Player 2 '" << player2.name << "' wins the match against Player 1 '" << this->name << "'\n";
	else std::cout << "It's a tie between Player 1 '"<<this->name<<"' and Player2 '"<<player2.name<<"'";
}
void Duelist::setName(std::string name)
{
	this->name = name;
}