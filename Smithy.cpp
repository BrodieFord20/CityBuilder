//Implementation file for Smithy header file
#include"Smithy.h"
//Default constructor for Smithy, initializes variables and sets the smithy price
Smithy::Smithy()
{
	metalModifier = 0;
	lumberPrice = 30 + this->metalModifier;
	metalPrice = 15 + this->metalModifier * .5;
	goldPrice = 8 + this->metalModifier * .334;
}

//Function for loading a saved game
void Smithy::loadgame(fstream &savefile)
{
//Variable modifier created
	int modifier;

//File object used to retrieve the modifier from the file
	savefile >> modifier;

//Set our metalModifier variable to the modifier in the file
	metalModifier = modifier;
}

//Function to add one to the number of Smithys created and sets the prices of the resources
void Smithy::SmithyModifier()
{
	metalModifier += 1;
	lumberPrice = 30 + this->metalModifier;
	metalPrice = 15 + this->metalModifier * .5;
	goldPrice = 8 + this->metalModifier * .334;
}

//Funtion will return metal modifier
int Smithy::getmetalModifier()
{
	return metalModifier;
}

