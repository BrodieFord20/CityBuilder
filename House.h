//Header file for House
#ifndef House_H
#define House_H
#include<iostream>
#include<string>
#include<fstream>
#include"Building.h"
#include<ctime>
using namespace std;

class House : public Building
{
public:
//Variable for keeping track of how many Houses were built
	int houseModifier;

//Variable to keep track of how many people live in the house
	int numberOfPeople;

//Calling of constructor
	House();

//Function to access the saved file, using a pass by reference object
	void loadgame(fstream &savefile);

//Calling of funciton to set GoldMineModifier
	void BuildHouseModifier();


//Calling of funciton to get GoldMineModifier
	int gethouseModifier();

//Calling of function to get numberOfPeople
	int getnumberOfPeople();
};

#endif