//Header file for City
#ifndef CITY_H
#define CITY_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GoldMine.h"
#include"Sawmill.h"
#include"Smithy.h"
#include"People.h"
#include"House.h"
#include<time.h>
using namespace std;

class City
{
public:
//Resource variables and variable for current time
	int Lumber;
	int Metal;
	int Gold;
	double currentTime;

//Calling of no-arg constructor
	City();

//Calling of arg constructor and passing in a saved file by reference
	void loadgame(fstream &SavedGame);

//Calling of producing resource functions and growing population
	void populationGrowth();

//Functions pass in a variable for timer, a People object and their correct building object to access their Member functions and variables
	int produceLumber(double &previoustimer, People founder, Sawmill lumbermod);
	int produceMetal(double &previoustimer, People founder, Smithy metalmod);
	int produceGold(double &previoustimer, People founder, GoldMine goldmod);

//Calling of building functions, passing in the correct building object to get its member variable price
	void buildSawmill(Sawmill &Price);
	void buildGoldMine(GoldMine &Price);
	void buildSmithy(Smithy &Price);
	void buildHouse(House &Price, People &assignments);

//Calling of subtracting resource functions
	void subtractLumber();
	void subtractMetal();
	void subtractGold();

//Caling of get functions for resources and population
	int getPopulation(People Totals);
	int getLumber();
	int getMetal();
	int getGold();

//Cheat Code Function
	void cheatCode();
};


#endif