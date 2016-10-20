//Header file for Sawmill
#ifndef SAWMILL_H
#define SAWMILL_H
#include<iostream>
#include<string>
#include<fstream>
#include"Building.h"
using namespace std;

class Sawmill : public  Building
{
public:
//Variable for keeping track of how many Sawmills were built
	int lumberModifier;

//Calling of constructor
	Sawmill();

//Function to access the saved file, using a pass by reference object
	void loadgame(fstream &savefile);

//Calling of funciton to set GoldMineModifier
	void SawmillModifier();

//Calling of funciton to get GoldMineModifier
	int getlumberModifier();
};

#endif