#include "House.h"

//No arg-constructor setting the resource prices and sets the houseModifier to 0
House::House()
{
	houseModifier = 0;
	lumberPrice = 30 + this->houseModifier;
	metalPrice = 15 + this->houseModifier * .5;
	goldPrice = 8 + this->houseModifier * .334;
}

//Function for loading a saved game
void House::loadgame(fstream &savefile)
{
//Variable modifier created
	int modifier;

//File object used to retrieve the modifier from the file
	savefile >> modifier;

//Set our houseModifier variable to the modifier in the file
	houseModifier = modifier;
}

//Function to add one to the number of Houses created and sets the prices of the resources
void House::BuildHouseModifier()
{
//Declare time
	srand(time(NULL));
	houseModifier += 1;
	lumberPrice = 30 + this->houseModifier;
	metalPrice = 15 + this->houseModifier * .5;
	goldPrice = 8 + this->houseModifier * .334;

//numberOfPeople set to a random number between 1-4
	numberOfPeople = rand() % 3 + 1;
}

//Returns number of houses built
int House::gethouseModifier()
{
	return houseModifier;
}

//Returns the number of people
int House::getnumberOfPeople()
{
	return numberOfPeople;
}
