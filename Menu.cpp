#include "Menu.h"
using namespace std;

Menu::Menu()
{
	
	



}



void Menu::displayMenu()
{
	cout << "            +-----------------------------------------------------+" << endl;
	cout << "            | +-------------------------------------------------+ |" << endl;
	cout << "            | |                                                 | |" << endl;
	cout << "            | |             BATTLE SHIP (BOOTLEG)               | |" << endl;
	cout << "            | |                                                 | |" << endl;
	cout << "            | |               BY Karan Phadnis                  | |" << endl;
	cout << "            | |                                                 | |" << endl;
	cout << "            + +-------------------------------------------------+ |" << endl;
	cout << "            +-----------------------------------------------------+" << endl << endl;


	cout << "            +-----------------------------------------------------+" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            |                     OPTIONS:                        |" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            |		    1. Player vs Player                   |" << endl;
	cout << "            |               2. Player vs Computer(AI)             |" << endl;
	cout << "            |               3. Rules                              |" << endl;
	cout << "            |               4. Quit Game                          |" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            +-----------------------------------------------------+" << endl << endl;
}

void Menu::gameRules()
{
	system("cls");
	cout <<endl<< "			Welcome to the Game of Battle Ship.						" << endl;
	cout << "Objective: sink your opponents ships by guessing where they are located on the" << endl << "board. First one to do so wins THE game." << endl << endl;
	cout << "-> The first board is YOUR board with the pieces that you placed and the second" << endl << "   board is the board that containts your OPPONENTS pieces." << endl << endl << "-> When you want to destroy a piece, type in the CAPITAL letter corresponding to the" << endl << "   row first and then the column." << endl << "	(ie.) 'AC' is the first row and the third column."<< endl << endl;
	
	cout << "-> When a player HITS a ship, it will appear as a 'X' on the player's OPPONENT'S   GRID and a 'X' on the opponent's YOUR GRID." << endl << endl;
	cout << "-> When a player MISSES a ship, it will appear as a '#' on the player's            OPPONENT'S  GRID and a '#' on the opponent's YOUR GRID." << endl << endl << endl;
	cout << "-> PIECES:    @@@@@    <- AIRCRAFT CARRIER          TTTT     <- BATTLE SHIP        ";
	cout << "           UUU      <- SUBMARINE                 YYY      <- DESTROYER       ";
	cout << "              PP       <- PATROL BOAT                      " << endl;

	cout << "          +--------------  Press Enter to Continue  ----------------+" << endl;
	cin.ignore(1000, '\n');
	if (cin.get() == '\n')
	{
		system("cls");
		displayMenu();
	}
		


		/*
	int returnValue;
//	cout << "Press 1 to return to the menu: "
	while (true)
		cout << "Press 1 to return to the menu: ";
		cin >> returnValue;
		if (returnValue == 1)
			break;
			*/
}

void Menu::executeMenu()
{
	displayMenu();
	int optionNumber;
	cout << "	      Please enter a number indicating your option (1-4): "<< endl<<"	      	      	      	     ";
	cin >> optionNumber;
	//cin.ignore(1000, '\n');

	while (true)
	{
		if (optionNumber <= 0 || optionNumber > 4){
			cout << "Please enter a valid number: ";
			cin >> optionNumber;
		}
		else break;
	}
	while (true)
	{
		if (optionNumber <= 0 || optionNumber > 4){
			cout << "Please enter a valid number: ";
			cin >> optionNumber;
		}
		else  if (optionNumber == 3)
		{
			gameRules();
			cout << endl<<endl;
			cout << "Please enter a number indicating your option (1-4): ";
			cin >> optionNumber;
		}
		else break;
	}

	
	
	switch (optionNumber){
		case 1:	
			//while (true){
				system("cls");
				pvpGame = new PvP;
				pvpGame->playPvPgame();
				break;
			//}
		case 2:
			/*system("cls");

			cout << endl << endl << endl;
			cout << "            +-----------------------------------------------------+" << endl;
			cout << "            |                                                     |" << endl;
			cout << "            |		                                          |" << endl;
			cout << "            |                Player vs Computer(AI)               |" << endl;
			cout << "            |             !! STILL UNDER CONSTRUCTION !!          |" << endl;
			cout << "            |                                                     |" << endl;
			cout << "            |                                                     |" << endl;
			cout << "            +----------------Press ENTER to Continue--------------+" << endl << endl;;

			cin.ignore(1000, '\n');
			if (cin.get() == '\n')
			{
				system("cls");
				executeMenu();
			}
			
			break;
			*/


		case 3: //never gets to here;
		case 4: exit(true); 
		
	}

	



}



Menu::~Menu()
{
}
