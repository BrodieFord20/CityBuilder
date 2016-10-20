//Header file for GoldMine
#ifndef GoldMine_H
#define GoldMine_H
#include<iostream>
#include<string>
#include<fstream>
#include"Building.h"
using namespace std;

class GoldMine : public  Building
{
public:
//Variable for keeping track of how many GoldMines were built
	int GoldModifier;

//Calling of constructor
	GoldMine();

//Function to access the saved file, using a pass by reference object
	void loadgame(fstream &savefile);

//Calling of funciton to set GoldMineModifier
	void GoldMineModifier();

//Calling of function to get GoldMineModifier
	int getGoldModifier();

};

#endif