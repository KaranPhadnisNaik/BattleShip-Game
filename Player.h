#ifndef PLAYER_H
#define PLAYER_H

#include <string>



class Player
{
public:
	Player();
	void printBoards();
	void setStartingPieces();
	void placeInProperPosition();
	void insertShip(int index);
	


	bool checkgrid(int row, int column);
	void insertIntoGrid(int row, int column, char character, bool whatGridToInsert);
	char whatLetterIsAt(int row, int column);


	std::string AreCoordinatesSyntacticallyCorrect(std::string& coordinates);
	char PlayerGrid[11][11];
	
	~Player();

private:
	
	char OpponentGrid[11][11]; 
	
};

#endif