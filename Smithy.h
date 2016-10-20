//Header file for Smithy
#ifndef Smithy_H
#define Smithy_H
#include<iostream>
#include<string>
#include<fstream>
#include"Building.h"
using namespace std;

class Smithy : public  Building
{
public:
	 
//Variable for keeping track of how many Smithys were built
	int metalModifier;

//Calling of Constructor
	Smithy();

//Function to access the saved file, using a pass by reference object
	void loadgame(fstream &savefile);

//Calling of funciton to set GoldMineModifier
	void SmithyModifier();


//Calling of funciton to get GoldMineModifier
	int getmetalModifier();
};
#endif
