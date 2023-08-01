/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lachezar Tsvetkov
* @idnumber 62515
* @task 4
* @compiler VCC
*/
#include<iostream>

#include"Duelist.hpp"

using namespace std;
int main()
{
	Deck deck1("Ultimate Deck");
	deck1.addCard(new MonsterCard ("MonsterCard#1", "This legendary dragon is a powerful engine of destruction.", 5, 3000, 2500));
	deck1.addCard(new MonsterCard ("MonsterCard#2", "wizard.", 64, 2500, 2100));
	deck1.addCard(new MonsterCard("MonsterCard#3", "The dot.", 6, 2500, 2100));
	deck1.addCard(new MonsterCard("MonsterCard#4", "The wizard.", 6, 2500, 2100));
	deck1.addCard(new MonsterCard("MonsterCard#5", "The spider wizard.", 6, 2500, 2100));

	deck1.addCard(new MagicCard("MagicCard #1", "Eats Bananas", 15, Type::SPELL));

	Duelist Aikido("Aikido");
	Aikido.setDeck(deck1);

	Duelist Hibita("Hibita");
	Hibita.setDeck(deck1);

	Aikido.duel(Hibita);


	//WARNING!!!!! Below hasn't been updated for the latest improvisations

	/*
	deck1.changeMonsterCard(magician, 0);


	PendulumCard error("Error of Errors", "Gives Error to all cards", 6, 2500, 1000, 5, Type::BUFF);
	PendulumCard correct("Error Removal", "Removes all errors of errors", 6, 1000, 2500, 7, Type::SPELL);
	deck1.addCard(error);
	deck1.changeCard(correct, 0);

	deck1.printDeck();

	Duelist krizel("Kineti");
	krizel.setDeck(deck1);
	krizel.saveFile("Kineti'sDeck.txt");
	krizel.readFile("TestFileXXX.txt");
	krizel.getDeck().printDeck();
	*/

	/*
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 12, 2500, 2100);
	
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 20, Type::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 1, Type::TRAP);
	
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 5, 1200, 600, 8, Type::SPELL);
	
	Duelist firstDuelist("Ivan Ivanov");


	firstDuelist.getDeck().setName("Magician Deck");
	firstDuelist.getDeck().addMonsterCard(dragon);
	firstDuelist.getDeck().addMagicCard(swords);
	firstDuelist.getDeck().addMonsterCard(magician);
	firstDuelist.getDeck().addMagicCard(cylinder);
	firstDuelist.getDeck().addPendulumCard(timegazer);

	firstDuelist.getDeck().printDeck();

	firstDuelist.saveFile("magician_deck.txt");

	firstDuelist.readFile("TestFile.txt");

	firstDuelist.getDeck().printDeck();
	MagicCard box("Mystic Box", "Destroy one monster.", 12, Type::SPELL);
	firstDuelist.getDeck().changeMagicCard(box, 0);



	*/

	/*
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 11, 3000, 2500);
	MonsterCard mag("Mag", "crab", 200, 2, 54);
	MonsterCard otato("BPotat", "Poootato", 422, -3000, 1231231);

	MagicCard mCard1("HBSAJK", "bkahsdbj", Type::buff);
	MagicCard mCard2("aaa", "aaa", Type::spell);


	Deck deck1("what is this e=deck");
	deck1.addMonsterCard(mag);
	deck1.addMonsterCard(dragon);

	deck1.addMagicCards(mCard1);
	deck1.addMonsterCard(otato);
	

	Duelist duel("Peter");
	duel.setDeck(deck1);
	duel.getDeck().setName("Testing#1");


	duel.saveFile("TestFileXXX.txt");
	cout << "Sacing deck\n";
	duel.getDeck().printDeck();





	duel.getDeck().clearDeck();
	duel.readFile("TestFile.txt");
	cout << "Replacing deck\n";
	duel.getDeck().printDeck();
	*/

	/*
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	MonsterCard mag("Mag", "crab", 2, 54);
	MonsterCard potato("Potato", "Pootato", 3000, 121);

	MagicCard mCard1("Magician'sCard #1 ", "The first card to exist", Type::buff);
	MagicCard mCard2("Screamer", "Screames 'AAAAAAAAAAAAAAAAA' throught the game", Type::spell);
	
	Deck deck1("what is this deck?");
	deck1.addMonsterCard(dragon);
	deck1.addMonsterCard(mag);
	deck1.addMonsterCard(potato);
	deck1.addMagicCards(mCard1);


	deck1.printDeck();

	deck1.changeMagicCard(mCard2, 0);
	deck1.printDeck();
	*/
}