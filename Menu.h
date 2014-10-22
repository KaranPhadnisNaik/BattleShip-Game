#ifndef MENU_H
#define MENU_H
#include "PvP.h"
#include<iostream>
class Menu
{
public:
	Menu();
	void displayMenu();
	void executeMenu();
	void gameRules();
	~Menu();

private:
	PvP* pvpGame;
};

#endif