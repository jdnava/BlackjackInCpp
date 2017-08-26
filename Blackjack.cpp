//----------------------------------------------------------------------------------------
//
//  main.cpp
//  Blackjack Sim
//
//  Created by JD on 8/3/17.
//  Copyright © 2017 JD. All rights reserved.
//
//----------------------------------------------------------------------------------------
// library calls and syntax/output formating
#include <iostream>
#include <array>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>    // std::random_shuffle

//#include "Table.h"
//#include "Person.h"
//#include "Player.h"
//#include "Dealer.h"
#include "AllClasses.h"

// GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHIC
// GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHIC
// GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHIC
// GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHIC
// GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHIC
// GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHICS OPENGL GRAPHIC



// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA
// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA
// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA
// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA
// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA
// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA
// END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRAPHICS OPENGL END GRA

using namespace std;


//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN
//START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN START MAIN

int main() {
//	CASINO OBJECTS
//	Table array
	int const NUMOFTABLES = 10;
	Table* casinoTablesArray[NUMOFTABLES];
//	Dealer array
	int const NUMOFDEALERS = 10;
	Table* casinoDealterArray[NUMOFTABLES];
//	CasinoPlayerVector
//	int const NUMOFTABLES = 10;
	vector<Table*> casinoPlayerVector;

//	PERSON TESTING
	//creation
//	cout << "PERSON TESTING" << endl;
	Person person1 ("Pernell", 1000);
	Dealer dealer1 ("Dean", 2000, 3);
	Player player1 ("Pluto", 3000);
	player1.setplayerBetForWin(1);
	player1.setplayerBetForLoss(1);
	Player player2 ("Sam", 4000);
	player2.setplayerBetForWin(.5);
	player2.setplayerBetForLoss(.5);
	Player player3 ("Jack", 5000);
	player3.setplayerBetForWin(600);
	player3.setplayerBetForLoss(600);
	Player player4 ("Juno", 6000);
	player4.setplayerBetForWin(1);
	player4.setplayerBetForLoss(2);
	Player player5 ("Louis", 7000);
	player5.setplayerBetForWin(3);
	player5.setplayerBetForLoss(6);
	Player player6 ("Ger", 8000);
	player6.setplayerBetForWin(0);
	player6.setplayerBetForLoss(0);
	Player player7 ("Max", 9000);
	player7.setplayerBetForWin(0);
	player7.setplayerBetForLoss(0);
	Player player8 ("John Snow", 10000);
	player8.setplayerBetForWin(0);
	player8.setplayerBetForLoss(0);
	
	
	//display
//	cout << dealer1.getName() << endl;
//	cout << dealer1.getTotalMoney() << endl;
//	cout << player1.getName() << endl;
//	cout << player1.getTotalMoney() << endl;
//	cout << endl;

////  SHOE TESTING
//	cout << "SHOE TESTING" << endl;
//	int numbOfDeck;
//	//cout << "enter a number "; cin >> numbOfDeck;
//	numbOfDeck = 2;
////	Shoe testshoe(numbOfDeck);//stack
	
	
//	TABLE TESTING
//	cout << "TABLE TESTING" << endl;
	
	// Table creation
	Table table1;
	casinoTablesArray[0] = table1.getTablePtr();
	
	//adding people to table
	casinoTablesArray[0]->setDealer(&dealer1); //DEALER
	
	int player1totable = 1;
	casinoTablesArray[0]->setPlayer(player1totable, &player1);
	player1.getTablePtr()->setPlayerTableBet(player1totable, player1.getBet(player1.getplayerBetForLoss()), 0);
	
	int player2totable = 2;
	casinoTablesArray[0]->setPlayer(player2totable, &player2);
	player1.getTablePtr()->setPlayerTableBet(player2totable, player2.getBet(player2.getplayerBetForLoss()), 0);

	int player3totable = 3;
	casinoTablesArray[0]->setPlayer(player3totable, &player3);
	player1.getTablePtr()->setPlayerTableBet(player3totable, player3.getBet(player3.getplayerBetForLoss()), 0);

	int player4totable = 4;
	casinoTablesArray[0]->setPlayer(player4totable, &player4);
	player1.getTablePtr()->setPlayerTableBet(player4totable, player4.getBet(player4.getplayerBetForLoss()), 0);

	int player5totable = 6;
	casinoTablesArray[0]->setPlayer(player5totable, &player5);
	player1.getTablePtr()->setPlayerTableBet(player5totable, player5.getBet(player5.getplayerBetForLoss()), 0);

	int player6totable = 7;
	casinoTablesArray[0]->setPlayer(player6totable, &player6);
	player1.getTablePtr()->setPlayerTableBet(player6totable, player6.getBet(player6.getplayerBetForLoss()), 0);
	
	//displays Table
//	casinoTablesArray[0]->tableDisplay();
	
	//displays Shoe
//	casinoTablesArray[0]->displayShoe();
//	cout << endl;

//	DEAL TESTING
	dealer1.startDeal();
	cout << endl;

//	// outputs all cards to cut/shuffle card
//	int fullShoeSize = casinoTablesArray[0]->shoeSize();
//	for (int i = 1; i < fullShoeSize; i++){
//		int card = casinoTablesArray[0]->getShoeCard();
//		if (card == 0 || card == -1){
//			fullShoeSize=1;
//		}
//		cout << table1.cardTranslator(card) << endl;
//	}
	
	casinoTablesArray[0]->tableDisplay();
//	casinoTablesArray[0]->displayShoe();
//	cout << endl;
	


	
////  SHOE TESTING in table
//	cout << "SHOE TESTING in table" << endl;
//	//display count and stack 1
//	table1.fillShoe(2);
//	table1.displayShoe();
//	cout << endl << "Dealt Card " << table1.getShoeCard() << endl << endl;
//	table1.displayShoe();
//	//display count and stack 2
//	table1.fillShoe(1);
//	table1.displayShoe();
//	cout << endl << "Dealt Card " << table1.getShoeCard() << endl << endl;
//	table1.displayShoe();
//	cout << endl;

	
//	GRAPHICS TESTING
	
	return 0;
}
//END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAI
//END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAI
//END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAI
//END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAI
//END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAIN END MAI
