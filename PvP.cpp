#include "PvP.h"

#include <string>
#include <iostream>
using namespace std;


const bool PLAYERGRID = true;
const bool OPPONENTGRID = false;

PvP::PvP()
{
//	system("cls");
}


PvP::~PvP()
{
}

void PvP::player1checker()
{
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << "                 Press ENTER if Player 1 in front of the screen?" << endl;
	cin.ignore(1000, '\n');
}

void PvP::player2checker()
{
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << "                 Press ENTER if Player 2 in front of the screen?" << endl;
	cin.ignore(1000, '\n');
}

void PvP::playPvPgame()
{

	// SETS UP THE PIECES FOR BOTH THE PLAYERS
	string response;
	system("cls");

	cout << endl << endl << endl;
	cout << "            +-----------------------------------------------------+" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            |		                                          |" << endl;
	cout << "            |                Player 1 vs Player 2                 |" << endl;
	cout << "            |               ~~~GET READY TO PLAY~~~               |" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            +----------------Press ENTER to Continue--------------+" << endl << endl;;

	cin.ignore(1000, '\n');
	if (cin.get() == '\n')
		system("cls");
	system("cls");


	player1checker();

	if (cin.get() == '\n'){
		system("cls");
		player1.setStartingPieces();
	}

	player2checker();

	if (cin.get() == '\n'){
		system("cls");
		player2.setStartingPieces();
	}

	system("cls");

	int index = 0;
	int rowValue;
	int columnValue;
	string coordinates;

	cout << endl << endl << endl;
	cout << "            +-----------------------------------------------------+" << endl;
	cout << "            | +-------------------------------------------------+ |" << endl;
	cout << "            | |                                                 | |" << endl;
	cout << "            | |             BATTLE SHIP (BOOTLEG)               | |" << endl;
	cout << "            | |                                                 | |" << endl;
	cout << "            | |               BY Karan Phadnis                  | |" << endl;
	cout << "            | |             (ALL RIGHTS RESERVED)               | |" << endl;
	cout << "            + +-------------------------------------------------+ |" << endl;
	cout << "            +-----------------------------------------------------+" << endl << endl;

	cout << "            Now that you have set up your pieces, get ready to PLAY" << endl;
	cout << "            +--------------  Press Enter to Play  ----------------+" << endl << endl;



	if (cin.get() == '\n'){
		system("cls");

	}

	system("cls");

	bool whichPlayersTurn = true;

	while (true)
	{


		
		if (whichPlayersTurn){
			player1checker();
			player1.printBoards();
		}
		else{
			player2checker();
			player2.printBoards();
		}
		cout << "Enter the coordinates where would you like to attack?: ";
		cin >> coordinates;
		cin.ignore(1000, '\n');

		coordinates = player1.AreCoordinatesSyntacticallyCorrect(coordinates);

		index = 0;

		while (index < 2)
		{
			switch (coordinates[index]){
			case 'A': 	if (index == 0) 	rowValue = 1; else columnValue = 1; index++; break;
			case 'B': 	if (index == 0) 	rowValue = 2; else columnValue = 2; index++; break;
			case 'C': 	if (index == 0) 	rowValue = 3; else columnValue = 3; index++; break;
			case 'D': 	if (index == 0) 	rowValue = 4; else columnValue = 4; index++; break;
			case 'E': 	if (index == 0) 	rowValue = 5; else columnValue = 5; index++; break;
			case 'F': 	if (index == 0) 	rowValue = 6; else columnValue = 6; index++; break;
			case 'G': 	if (index == 0) 	rowValue = 7; else columnValue = 7; index++; break;
			case 'H': 	if (index == 0) 	rowValue = 8; else columnValue = 8; index++; break;
			case 'I': 	if (index == 0) 	rowValue = 9; else columnValue = 9; index++; break;
			case 'J': 	if (index == 0) 	rowValue = 10; else columnValue = 10; index++; break;
			}


		}
		char character;
		if (whichPlayersTurn){
			if (player2.checkgrid(rowValue, columnValue))
			{
				character = player2.whatLetterIsAt(rowValue, columnValue);
				player2.insertIntoGrid(rowValue, columnValue, 'X', PLAYERGRID);
				player1.insertIntoGrid(rowValue, columnValue, character, OPPONENTGRID);
				system("cls");
				player1.printBoards();
				cout << "Player 1, You hit a ship!" << endl;
				cout << "Press ENTER to continue" << endl;
				if (cin.get() == '\n'){
					//system("cls");

				}
				
			}
			else
			{
				player2.insertIntoGrid(rowValue, columnValue, '#', PLAYERGRID);
				player1.insertIntoGrid(rowValue, columnValue, '#', OPPONENTGRID);
				system("cls");
				player1.printBoards();
				cout << "Player 1, You missed!" << endl;
				cout << "Press ENTER to continue" << endl;
				if (cin.get() == '\n'){
					//system("cls");

				}
			}
			whichPlayersTurn = false;
		}
		else
		{
			if (player1.checkgrid(rowValue, columnValue))
			{
				character = player1.whatLetterIsAt(rowValue, columnValue);
				player1.insertIntoGrid(rowValue, columnValue, 'X', PLAYERGRID);
				player2.insertIntoGrid(rowValue, columnValue, character, OPPONENTGRID);
				system("cls");
				player2.printBoards();
				cout << "Player 2, You hit a ship!" << endl;
				cout << "Press ENTER to continue" << endl;
				if (cin.get() == '\n'){
					//system("cls");

				}

			}
			else
			{
				player1.insertIntoGrid(rowValue, columnValue, '#', PLAYERGRID);
				player2.insertIntoGrid(rowValue, columnValue, '#', OPPONENTGRID);
				system("cls");
				player2.printBoards();
				cout << "Player 2, You missed!" << endl; 
				cout << "Press ENTER to continue" << endl;
				if (cin.get() == '\n'){
					//system("cls");

				}
			}
			whichPlayersTurn = true;
		}
	
		int PLAYERTHATWONTHEGAME = CheckForWinner();
		
		if (PLAYERTHATWONTHEGAME != 0){
			if (PLAYERTHATWONTHEGAME == 1){
				cout << "          Player 1 Won!      " << endl;
				cout << "          Press ENTER to continue      " << endl;
				if (cin.get() == '\n')
					break;
			}
			else if (PLAYERTHATWONTHEGAME == 2)
			{
				if (PLAYERTHATWONTHEGAME == 1){
					cout << "          Player 2 Won!      " << endl;
					cout << "          Press ENTER to continue      " << endl;
					if (cin.get() == '\n')
						break;
				}
			}
		}
		

	}
}

int PvP::CheckForWinner()
{

	int row = 1;
	int column = 1;

	bool player1Alive = false;
	bool player2Alive = false;

	while (row < 11){
		while (column < 11){

			if (player1.PlayerGrid[row][column] == '@' || player1.PlayerGrid[row][column] == 'T' || player1.PlayerGrid[row][column] == 'U' || player1.PlayerGrid[row][column] == 'Y' || player1.PlayerGrid[row][column] == 'P')
				player1Alive = true;
			if (player2.PlayerGrid[row][column] == '@' || player2.PlayerGrid[row][column] == 'T' || player2.PlayerGrid[row][column] == 'U' || player2.PlayerGrid[row][column] == 'Y' || player2.PlayerGrid[row][column] == 'P')
				player2Alive = true;

			column++;
		}
		row++;
		column = 0;
	}

	if (player1Alive == true && player2Alive == true)
		return 0;
	if (player1Alive == true)
		return 1;
	if (player2Alive == true)
		return 2;


}