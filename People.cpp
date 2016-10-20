#include"People.h"

//No-Arg constructor for People, all variables of people are initialized to zero
People::People()
{
	lumberJacks = 0;
	blackSmiths = 0;
	merchants = 0;
}

//Function for accessing a game that is saved, using the object pass in to retrieve data in the file
void People::loadgame(fstream &SavedGame)
{
	int Lumberjacks;
	int Blacksmiths;
	int Merchants;

//The SavedGame object will read in the people from the saved file
	SavedGame >> Lumberjacks;
	SavedGame >> Blacksmiths;
	SavedGame >> Merchants;

//This statement will then set the number of people from the file to the correct people variables
	this->lumberJacks = Lumberjacks;
	this->blackSmiths = Blacksmiths;
	this->merchants = Merchants;
}


//Function for setting the population
void People::setpopulation(House newhouse)
{
	system("CLS");
	cout << "Please assign the people that have moved into the house you just created." << endl;
	cout << "1 = lumberjack \n2 = blacksmith \n3 = merchant" << endl;
	int select;
	for (int i = 0; i < newhouse.getnumberOfPeople();)
	{
		cin >> select;

//Switch statement that increments the population if the correct case is selected
		switch (select)
		{
//Adds a lumberjack
			case 1:
			{
				this->addLumberjack();
				i++;
				break;
			}

//Adds a blacksmith
			case 2:
			{
				this->addBlacksmith();
				i++;
				break;
			}

//Adds a merchant
			case 3:
			{
				this->addMerchant();
				i++;
				break;
			}
			default:
			{
				cout << "Please select a real option." << endl;
				break;
			}
		}
	}
}

//Function for adding a lumberjack
void People::addLumberjack()
{
	lumberJacks += 1;
}

//Function for adding a blacksmith
void People::addBlacksmith()
{
	blackSmiths += 1;
}

//Function for adding a merchant
void People::addMerchant()
{
	merchants += 1;
}

//Function for returning the number of lumberjacks
int People::getLumberjack()
{
	return lumberJacks;
}

//Function for returning the number of blacksmiths
int People::getBlacksmith()
{
	return blackSmiths;
}

//Function for returning the number of merchants
int People::getMerchant()
{
	return merchants;
}