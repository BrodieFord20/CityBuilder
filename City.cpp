//Implementation File for City header file
#include"City.h"



//Default constructor for City, initializes resource variables to zero
City::City()
{
	Lumber = 0;
	Metal = 0;
	Gold = 0;
}

//Arg-constructor for passing in a saved file, allows the user to start where they left off
void City::loadgame(fstream &SavedGame)
{
	int Lumber;
	int Metal;
	int Gold;

//The SavedGame object will read in the resources from the file
	SavedGame >> Lumber;
	SavedGame >> Metal;
	SavedGame >> Gold;

//This statement will set the resources from the file to the correct resource variables
	this->Lumber = Lumber;
	this->Metal = Metal;
	this->Gold = Gold;
}

//Returning the population of your city, passing in people object to obtain the member functions for the chosen people
int City::getPopulation(People Totals)
{
	return Totals.getLumberjack() + Totals.getBlacksmith() + Totals.getMerchant();
}

//Manipulating City produceLumber function, passing in timer, People and Sawmill object to access member functions and set variables
int City::produceLumber(double &woodTimer, People founder, Sawmill lumbermod )
{
	currentTime = time(NULL);

	if (founder.getLumberjack() > 400)
	{
//If this "if" statement is true than the user collects the resource Wood and the cool down timer starts
		if (currentTime - woodTimer > 1)
			{
				this->Lumber = Lumber + (10 + 2 * lumbermod.getlumberModifier() + founder.getLumberjack());
				cout << "You collected " << (10 + 2 * lumbermod.getlumberModifier() + founder.getLumberjack()) << " wood." << endl;
				woodTimer = time(NULL);
				return 0;
			}
//Else statement displaying that the user could not collect the Wood because the user must wait for the cool down timer
		else
			{
			cout << "could not collect wood. You must wait " << 1 - (currentTime - woodTimer) << " seconds" << endl;
				return 0;
			}
	}

	else if (currentTime - woodTimer > (5 - (founder.getLumberjack()*.01)))
			{
				this->Lumber = Lumber + (10 + 2 * lumbermod.getlumberModifier() + founder.getLumberjack());
				cout << "You collected " << (10 + 2 * lumbermod.getlumberModifier() + founder.getLumberjack()) << " wood." << endl;
				woodTimer = time(NULL);
				return 0;
			}
	else
			{
		cout << "Could not collect wood. You must wait " << (5 - (founder.getLumberjack()*.01)) - (currentTime - woodTimer) << " seconds." << endl;
				return 0;
			}
	
}

//Manipulating City produceMetal function, passing in timer, People and Sawmill object to access member functions and set variables
int City::produceMetal(double &metalTimer, People founder, Smithy metalmod)
{
	currentTime = time(NULL);
	if (founder.getBlacksmith() > 400)
	{
//If this "if" statement is true than the user collects the resource Metal and the cool down timer starts
		if (currentTime - metalTimer > 1)
			{
				this->Metal = Metal + (6 + 1 * metalmod.getmetalModifier() + founder.getBlacksmith());
				cout << "You collected " << (6 + 1 * metalmod.getmetalModifier() + founder.getBlacksmith()) << " metal." << endl;
				metalTimer = time(NULL);
				return 0;
			}
		else
//Else statement displaying that the user could not collect the Metal because the user must wait for the cool down timer
			{
				cout << "could not collect metal. You must wait " << 1 - (currentTime - metalTimer) << " seconds" << endl;
				return 0;
			}
	}
	else if (currentTime - metalTimer > (5 - (founder.getBlacksmith()*.01)))
			{
				this->Metal = Metal + (6 + 1 * metalmod.getmetalModifier() + founder.getBlacksmith());
				cout << "You collected " << (6 + 1 * metalmod.getmetalModifier() + founder.getBlacksmith()) << " metal." << endl;
				metalTimer = time(NULL);
				return 0;
			}
	else
			{
				cout << "Could not collect metal. You must wait " << (5 - (founder.getBlacksmith()*.01)) - (currentTime - metalTimer) << " seconds." << endl;
				return 0;
			}

}

//Manipulating City produceGold function, passing in timer, People and Sawmill object to access member functions and set variables
int City::produceGold(double &goldTimer, People founder, GoldMine goldmod)
{
	{
		currentTime = time(NULL);
		if (founder.getMerchant() > 400)
		{
//If this "if" statement is true than the user collects the resource Gold and the cool down timer starts
			if (currentTime - goldTimer > 1)
				{
					this->Gold = Gold + (3 + 1 * goldmod.getGoldModifier() + .5 * founder.getMerchant());
					cout << "You collected " << (3 + 1 * goldmod.getGoldModifier() + .5 * founder.getMerchant()) << " gold." << endl;
					goldTimer = time(NULL);
					return 0;
				}
			else
//Else statement displaying that the user could not collect the Gold because the user must wait for the cool down timer
				{
					cout << "could not collect gold. You must wait " << 1 - (currentTime - goldTimer) << " seconds" << endl;
					return 0;
				}
		}

		else if (currentTime - goldTimer > (5 - (founder.getMerchant()*.01)))
				{
					this->Gold = Gold + (3 + 1 * goldmod.getGoldModifier() + .5 * founder.getMerchant());
					cout << "You collected " << (3 + 1 * goldmod.getGoldModifier() + .5 * founder.getMerchant()) << " gold." << endl;
					goldTimer = time(NULL);
					return 0;
				}
		else
				{
					cout << "Could not collect gold. You must wait " << (5 - (founder.getMerchant()*.01)) - (currentTime - goldTimer) << " seconds." << endl;
					return 0;
				}

	}
}

//Function for building the Sawmill, pass in an object of Sawmill to access member functions and variables
void City::buildSawmill(Sawmill &Price)
	{
//If this "if" statement is correct then, the Sawmill will be built by subtracting the resources it needs
	if (this->Lumber > Price.getlumberPrice() && this->Metal > Price.getmetalPrice() && this->Gold > Price.getgoldPrice())
	{
		cout << "you succesfully built a sawmill" << endl;
		Price.SawmillModifier();
		this->Lumber -= Price.getlumberPrice();
		this->Metal -= Price.getmetalPrice();
		this->Gold -= Price.getgoldPrice();
	}
	else
		cout << "Construct additional pylons." << endl;
	}

//Function for building the Smithy, pass in an object of Smithy to access member functions and variables
void City::buildSmithy(Smithy &Price)
	{
//If this "if" statement is correct then, the Smithy will be built by subtracting the resources it needs
		if (this->Lumber > Price.getlumberPrice() && this->Metal > Price.getmetalPrice() && this->Gold > Price.getgoldPrice())
			{
				cout << "you succesfully built a smithy" << endl;
				Price.SmithyModifier();
				this->Lumber -= Price.getlumberPrice();
				this->Metal -= Price.getmetalPrice();
				this->Gold -= Price.getgoldPrice();
			}
	}

//Function for building the GoldMine pass in an object of GoldMine to access member functions and variables
void City::buildGoldMine(GoldMine &Price)
	{	
//If this "if" statement is correct then, the GoldMine will be built by subtracting the resources it needs
		if (this->Lumber > Price.getlumberPrice() && this->Metal > Price.getmetalPrice() && this->Gold > Price.getgoldPrice())
			{
			cout << "you succesfully built a goldmine" << endl;
				Price.GoldMineModifier();
				this->Lumber -= Price.getlumberPrice();
				this->Metal -= Price.getmetalPrice();
				this->Gold -= Price.getgoldPrice();
			}
	}

//Function for building the House, pass in an object of House to access member functions and variables
void City::buildHouse(House &Price, People &assignments)
	{
//If this "if" statement is correct then, the House will be built by subtracting the resources it needs and will also assign the population using an object
		if (this->Lumber > Price.getlumberPrice() && this->Metal > Price.getmetalPrice() && this->Gold > Price.getgoldPrice())
			{
				cout << "you succesfully built a house" << endl;
				Price.BuildHouseModifier();
				this->Lumber -= Price.getlumberPrice();
				this->Metal -= Price.getmetalPrice();
				this->Gold -= Price.getgoldPrice();
				assignments.setpopulation(Price);
			}
	}

//Get function to return the total Lumber
int City::getLumber()
{
	return Lumber; 
}

//Get function to return the total Metal
int City::getMetal()
{
	return Metal;
}

//Get funtion to return the total Gold
int City::getGold()
{
	return Gold;
}

//Makes the cheat code for the user to start with the resources at 1000
void City::cheatCode()
{
	
		this->Lumber += 1000;
		this->Metal += 1000;
		this->Gold += 1000;
}