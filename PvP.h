#ifndef PVP_H
#define PVP_H

#include "Player.h"

class PvP
{
public:
	PvP();
	void playPvPgame();
	void player1checker();
	void player2checker();

	int CheckForWinner();

	~PvP();
private: 
	Player player1;
	Player player2;
};

#endif