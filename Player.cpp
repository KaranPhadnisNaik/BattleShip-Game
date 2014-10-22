#include "Player.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

const bool PLAYERGRID = true;
const bool OPPONENTGRID = false;

Player::Player()
{
	
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			PlayerGrid[i][j] = '~';
			OpponentGrid[i][j] = '~';

		}
	}


	char ArrayOfLetters[10] = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	for (int i = 0; i < 10; i++)
	{
		PlayerGrid[0][i+1] = ArrayOfLetters[i];
		PlayerGrid[i+1][0] = ArrayOfLetters[i];
		OpponentGrid[0][i + 1] = ArrayOfLetters[i];

		OpponentGrid[i + 1][0] = ArrayOfLetters[i];

	}
	PlayerGrid[0][0] = ' ';
	OpponentGrid[0][0] = ' ';

	//printBoards();
	//setStartingPieces();
}




void Player::setStartingPieces()
{
	printBoards();
	insertShip(0);
	insertShip(1);
	insertShip(2);
	insertShip(3);
	insertShip(4);
}

string Player::AreCoordinatesSyntacticallyCorrect(string& coordinates)
{
	bool SyntacticallycoordiantesAreOkay;

	while (true){
		SyntacticallycoordiantesAreOkay = true;
		if (coordinates.size() == 2)
		{
			int i = 0;
			while (i < 2){
				if (!isalpha(coordinates[i]) || islower(coordinates[i]))
					SyntacticallycoordiantesAreOkay = false;
				i++;
			}
		}

		if (coordinates.size() == 1 || SyntacticallycoordiantesAreOkay == false){
			cout << "Enter synatactically valid coordinates: ";
			cin >> coordinates;
		}
		else break;
	}

	return coordinates;
}


void Player::insertShip(int INDEX)
{
	
	string ArrayOfShips[5] = { "AIRCRAFT CARRIER (5 spaces)", "BATTLE SHIP (4 spaces)", "SUBMARINE (3 spaces)", "DESTROYER (3 spaces) ", "PATROL BOAT (2 spaces)" };
	string coordinates;
	
	




	while (true){
		cout << "Where do you want to place the " << ArrayOfShips[INDEX] << "?: ";
		cin >> coordinates;
		cin.ignore(1000, '\n');

		//checks if the coordinates are syntactically  correct, will repeat until they are
		// NOTE: THIS ASSUMES THAT THE PERSON ENTERS LETTER THAT ARE WITHIN THE RANGE OF THE BOARD

		coordinates = AreCoordinatesSyntacticallyCorrect(coordinates);


		/*bool SyntacticallycoordiantesAreOkay;

		while (true){
			SyntacticallycoordiantesAreOkay = true;
			if (coordinates.size() == 2)
			{
				int i = 0;
				while (i < 2){
					if (!isalpha(coordinates[i]) || islower(coordinates[i]))
						SyntacticallycoordiantesAreOkay = false;
					i++;
				}
			}

			if (coordinates.size() == 1 || SyntacticallycoordiantesAreOkay == false){
				cout << "Enter synatactically valid coordinates: ";
				cin >> coordinates;
			}
			else break;
		}

		*/
		// direction that you want to place the ship



		int placementDirection;
		string Dir;
		cout << "Direction you want the ship to point ( N / S / E / W ) **Note: Will build in opposite direction**: ";
		while (true)
		{
			cin >> Dir;
			cin.ignore(1000, '\n');
			if (Dir.size() == 1)
			{
				if (Dir[0] == 'N'){
					placementDirection = NORTH;
					break;
				}
				if (Dir[0] == 'S'){
					placementDirection = SOUTH;
					break;
				}
				if (Dir[0] == 'E'){
					placementDirection = EAST;
					break;
				}
				if (Dir[0] == 'W'){
					placementDirection = WEST;
					break;
				}
			}
			cout << "Enter proper value: ";

		}


		//concerts the letter coordinates into number coordinates
		int index = 0;
		int rowValue;
		int columnValue;
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


		// now check if the specifed ship fits within the board
		bool checker = false;
		bool willADDifTrue = true;
			
		if (INDEX == 0)	// MEANS 5-SPACE SHIP
		{



			if (placementDirection == NORTH)
			{
				if (rowValue + 4 <= 10)
				{
					for (int i = 0; i < 5; i++)
					{
						if (PlayerGrid[rowValue + i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 5; i++)
						{
							PlayerGrid[rowValue + i][columnValue] = '@';
							checker = true;

						}
					}
					break;

					
				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == SOUTH)
			{
				if (rowValue - 4 >= 1)
				{
					for (int i = 0; i < 5; i++)
					{
						if (PlayerGrid[rowValue - i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}
					if (willADDifTrue){
						for (int i = 0; i < 5; i++)
						{
							PlayerGrid[rowValue - i][columnValue] = '@';
							checker = true;

						}
					}
					break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection ==EAST)
			{
				if (columnValue - 4 >= 1)
				{
					for (int i = 0; i < 5; i++)
					{
						if (PlayerGrid[rowValue][columnValue-i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							break;
						}
					}

					for (int i = 0; i < 5; i++)
					{
						PlayerGrid[rowValue][columnValue - i] = '@';
						checker = true;

					}
					break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}
			if (placementDirection == WEST)
			{
				if (columnValue + 4 <= 10)
				{
					for (int i = 0; i < 5; i++)
					{
						if (PlayerGrid[rowValue][columnValue + i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							break;
						}
					}

					for (int i = 0; i < 5; i++)
					{
						PlayerGrid[rowValue][columnValue + i] = '@';
						checker = true;

					}
				//	break;


				}
			//	cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

		}

		if (INDEX == 1)	// MEANS 4-SPACE SHIP
		{



			if (placementDirection == NORTH)
			{
				if (rowValue + 3 <= 10)
				{
					for (int i = 0; i < 4; i++)
					{
						if (PlayerGrid[rowValue + i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}
					if (willADDifTrue){
						for (int i = 0; i < 4; i++)
						{
							PlayerGrid[rowValue + i][columnValue] = 'T';
							checker = true;

						}
					}
				//	break;


				}
			//	cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == SOUTH)
			{
				if (rowValue - 3 >= 1)
				{
					for (int i = 0; i < 4; i++)
					{
						if (PlayerGrid[rowValue - i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}
					if (willADDifTrue){
						for (int i = 0; i < 4; i++)
						{
							PlayerGrid[rowValue - i][columnValue] = 'T';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == EAST)
			{
				if (columnValue - 4 >= 1)
				{
					for (int i = 0; i < 4; i++)
					{
						if (PlayerGrid[rowValue][columnValue - i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 4; i++)
						{
							PlayerGrid[rowValue][columnValue - i] = 'T';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}
			if (placementDirection == WEST)
			{
				if (columnValue + 3 <= 10)
				{
					for (int i = 0; i < 4; i++)
					{
						if (PlayerGrid[rowValue][columnValue + i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 4; i++)
						{
							PlayerGrid[rowValue][columnValue + i] = 'T';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

		}

		if (INDEX == 2 || INDEX == 3 )	// MEANS 2 TYPES OF 3-SPACE SHIP
		{



			if (placementDirection == NORTH)
			{
				if (rowValue + 2 <= 10)
				{
					for (int i = 0; i < 3; i++)
					{
						if (PlayerGrid[rowValue + i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 3; i++)
						{
							if (INDEX == 2)
								PlayerGrid[rowValue + i][columnValue] = 'U';
							if (INDEX == 3)
								PlayerGrid[rowValue + i][columnValue] = 'Y';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == SOUTH)
			{
				if (rowValue - 2 >= 1)
				{
					for (int i = 0; i < 3; i++)
					{
						if (PlayerGrid[rowValue - i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 3; i++)
						{
							if (INDEX == 2)
								PlayerGrid[rowValue - i][columnValue] = 'U';
							if (INDEX == 3)
								PlayerGrid[rowValue - i][columnValue] = 'Y';
							checker = true;
						}
					}
					//break;


				}
			//	cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == EAST)
			{
				if (columnValue - 2 >= 1)
				{
					for (int i = 0; i < 3; i++)
					{
						if (PlayerGrid[rowValue][columnValue - i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue)
					{
						for (int i = 0; i < 3; i++)
						{
							if (INDEX == 2)
								PlayerGrid[rowValue][columnValue-i] = 'U';
							if (INDEX == 3)
								PlayerGrid[rowValue][columnValue-i] = 'Y';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}
			if (placementDirection == WEST)
			{
				if (columnValue + 2 <= 10)
				{
					for (int i = 0; i < 3; i++)
					{
						if (PlayerGrid[rowValue][columnValue + i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 3; i++)
						{
							if (INDEX == 2)
								PlayerGrid[rowValue][columnValue+i] = 'U';
							if (INDEX == 3)
								PlayerGrid[rowValue][columnValue+i] = 'Y';
							checker = true;
						}
					}
					//break;


				}
				//cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

		}
		if (INDEX == 4)	// MEANS 2-SPACE SHIP
		{



			if (placementDirection == NORTH)
			{
				if (rowValue + 1 <= 10)
				{
					for (int i = 0; i < 2; i++)
					{
						if (PlayerGrid[rowValue + i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 2; i++)
						{
							PlayerGrid[rowValue + i][columnValue] = 'P';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == SOUTH)
			{
				if (rowValue - 1 >= 1)
				{
					for (int i = 0; i < 2; i++)
					{
						if (PlayerGrid[rowValue - i][columnValue] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 2; i++)
						{
							PlayerGrid[rowValue - i][columnValue] = 'P';
							checker = true;

						}
					}
					//break;


				}
				//	cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

			if (placementDirection == EAST)
			{
				if (columnValue - 1 >= 1)
				{
					for (int i = 0; i < 2; i++)
					{
						if (PlayerGrid[rowValue][columnValue - i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue)
					{
						for (int i = 0; i < 2; i++)
						{
							PlayerGrid[rowValue][columnValue - i] = 'P';
							checker = true;

						}
					}
					//break;


				}
				//cout << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}
			if (placementDirection == WEST)
			{
				if (columnValue + 1 <= 10)
				{
					for (int i = 0; i < 2; i++)
					{
						if (PlayerGrid[rowValue][columnValue + i] != '~'){

							cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
							willADDifTrue = false;
							break;
						}
					}

					if (willADDifTrue){
						for (int i = 0; i < 2; i++)
						{
							PlayerGrid[rowValue][columnValue + i] = 'P';
							checker = true;

						}
					}
					//break;


				}
				//cout << endl << " You will have to find other coordinates for " << ArrayOfShips[INDEX] << "." << endl;
			}

		}





		



		if (checker)
			break;
		}

		system("cls");
		printBoards();

	
	


}



void Player::printBoards()
{
	cout <<"              " <<"Your Grid" << "                                   " << "Opponent's Grid" << endl<<endl;
	
	for (int i = 0; i < 11; i++)
	{
		cout << "        ";
		for (int j = 0; j < 11; j++)
		{
			cout << PlayerGrid[i][j] << " ";
		}
		cout << "                      ";
		for (int j = 0; j < 11; j++)
		{
			cout << OpponentGrid[i][j] << " ";
		}
		cout << endl << endl;
	}

}



bool Player::checkgrid(int row, int column)
{
	
	if (PlayerGrid[row][column] == '@' || PlayerGrid[row][column] == 'T' || PlayerGrid[row][column] == 'U' || PlayerGrid[row][column] == 'Y' || PlayerGrid[row][column] == 'P')
		return true;
	else
		return false;


}


void Player::insertIntoGrid(int row, int column, char character, bool whatGridToInsert)
{
	if (whatGridToInsert)
		PlayerGrid[row][column] = character;
	else
		OpponentGrid[row][column] = character;
}


char Player::whatLetterIsAt(int row, int column)
{
	char character = PlayerGrid[row][column];
	return character;

}


Player::~Player()
{
}
