//Implementation file for GoldMine header file
#include"GoldMine.h"

//No-arg Constructor for GoldMine, initializes variables and sets the GoldMine price for resources
GoldMine::GoldMine()
{
	GoldModifier = 0;
	lumberPrice = 60 + this->GoldModifier;
	metalPrice = 32 + this->GoldModifier * .5;
	goldPrice = 18 + this->GoldModifier * .334;

}

//Function for loading a saved game
void GoldMine::loadgame(fstream &savefile)
{
//Variable modifier created
	int modifier;

//File object used to retrieve the modifier from the file
	savefile >> modifier;

//Set our goldModifier variable to the modifier in the file
	GoldModifier = modifier;
}

//Function to add one to the number of GoldMines created and sets the prices of the resources
void GoldMine::GoldMineModifier()
{
	GoldModifier += 1;
	lumberPrice = 60 + this->GoldModifier;
	metalPrice = 32 + this->GoldModifier * .5;
	goldPrice = 18 + this->GoldModifier * .334;
}


//Function that will get the Gold modifier
int GoldMine::getGoldModifier()
{
	return GoldModifier;
}