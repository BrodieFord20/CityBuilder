//Header file for People
#ifndef People_H
#define People_H
#include "House.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class People
{
public:
//Calling of constructor
	People();

//People variables 
	int lumberJacks;
	int blackSmiths;
	int merchants;

//Calling of functions for adding people
	void setpopulation(House newhouse);
	void addLumberjack();
	void addBlacksmith();
	void addMerchant();

//Calling of functions to get those people
	int getLumberjack();
	int getBlacksmith();
	int getMerchant();

//Calling of function to load a saved game, passing in an object by reference
	void loadgame(fstream &SavedGame);
};

#endif