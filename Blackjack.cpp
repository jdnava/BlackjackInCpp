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
#include <algorithm>

//#include "Table.h"
//#include "Person.h"
//#include "Player.h"
//#include "Dealer.h"
#include "AllClasses.h"

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

//	PERSON TESTING - these objects and info will be created by users
	//creation
//	cout << "PERSON TESTING" << endl;
	Person person1 ("Theon", 1000);
	
	Dealer dealer1 ("Tyrion", 2000, 3);
	
	Player player1 ("Gilly", 3000);
	player1.setplayerBetForWin(1);
	player1.setplayerBetForLoss(1);
	
	Player player2 ("Sam", 4000);
	player2.setplayerBetForWin(.5);
	player2.setplayerBetForLoss(.5);
	
	Player player3 ("Gendry", 5000);
	player3.setplayerBetForWin(600);
	player3.setplayerBetForLoss(600);
	
	Player player4 ("Ned", 6000);
	player4.setplayerBetForWin(1);
	player4.setplayerBetForLoss(2);
	
	Player player5 ("Arya", 7000);
	player5.setplayerBetForWin(3);
	player5.setplayerBetForLoss(6);
	
	Player player6 ("Gilly", 8000);
	player6.setplayerBetForWin(0);
	player6.setplayerBetForLoss(0);
	
	Player player7 ("Brienne", 9000);
	player7.setplayerBetForWin(0);
	player7.setplayerBetForLoss(0);
	
	Player player8 ("John Snow", 10000);
	player8.setplayerBetForWin(0);
	player8.setplayerBetForLoss(0);
	
	
	//display persons at in casino
	person1.displayPerson(); cout << "--------------" << endl;

	dealer1.displayPerson(); cout << "--------------" << endl;
	
	player1.displayPerson(); cout << "--------------" << endl;

	player2.displayPerson(); cout << "--------------" << endl;

	player3.displayPerson(); cout << "--------------" << endl;

	player4.displayPerson(); cout << "--------------" << endl;

	player5.displayPerson(); cout << "--------------" << endl;

	player6.displayPerson(); cout << "--------------" << endl;

	player7.displayPerson(); cout << "--------------" << endl;

	player8.displayPerson(); cout << "--------------" << endl;
	
	cout << endl;
	
	
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
	
	//displays Shoe
	casinoTablesArray[0]->displayShoe();
	cout << endl;
	
	//displays Table
	casinoTablesArray[0]->tableDisplay();
	cout << endl;

//	DEAL TESTING
	dealer1.startDeal();
	cout << endl;

	casinoTablesArray[0]->tableDisplay();
	cout << endl;

	casinoTablesArray[0]->displayShoe();
	cout << endl;
	


	
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
