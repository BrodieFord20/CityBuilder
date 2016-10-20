#include"Sawmill.h"

//Default constructor for Sawmill, initializes variables and sets the sawmill price
Sawmill::Sawmill()
{
	lumberModifier = 0;
	lumberPrice = 18 + this->lumberModifier;
	metalPrice = 10 + this->lumberModifier * .5;
	goldPrice = 6 + this->lumberModifier * .334;
}

//Function for loading a saved game 
void Sawmill::loadgame(fstream &savefile)
{
//Variable Modifier created
	int modifier;

//File object used to retrieve the modifier from the file
	savefile >> modifier;

//Set our lumberModifier variable to the modifier in the file
	lumberModifier = modifier;
}

//Function to add one to the number of Sawmills created and sets the prices of the resources
void Sawmill::SawmillModifier()
{
	lumberModifier += 1;
	lumberPrice = 18 + this->lumberModifier;
	metalPrice = 10 + this->lumberModifier * .5;
	goldPrice = 6 + this->lumberModifier * .334;
}

//Function that will return lumber modifier
int Sawmill::getlumberModifier()
{
	return lumberModifier;
}


