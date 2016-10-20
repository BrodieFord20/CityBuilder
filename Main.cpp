#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include"City.h"
using namespace std;

int main()
{
//Variables
	srand(time(NULL));
	double woodTimer = time(NULL);
	double metalTimer = time(NULL);
	double goldTimer = time(NULL);

	string savedgame; //this string is used to select a previous games text file to load a saved game.
	char choice = '0';
	int select = 0;
	fstream loadfile;
	fstream savefile;

//Creating Objects
	City FoundingCity;
	People FoundingPeople;
	Sawmill FoundingSawmill;
	Smithy FoundingSmithy;
	GoldMine FoundingGoldMine;
	House FoundingHouse;

	
//Introduction
	cout << "Thank you for playing City Builder! \n" << endl;
	cout << "Do you have a saved game to load?Y/N" << endl;

//While loop to test answer of choice
	while (choice != 'N' && choice != 'Y')
	{
		cin >> choice;

//If the the choice was yes then the file that was saved is opened
		if (choice == 'Y')
		{
//The user will enter the file they want to open
			cin >> savedgame;
			loadfile.open(savedgame, ios::out | ios::in);
			if (loadfile.fail())
			{
				cout << "sorry couldnt open." << endl;
				return 0;
			}
//Steps through the file to get the information
			FoundingCity.loadgame(loadfile);
			FoundingPeople.loadgame(loadfile);
			FoundingSawmill.loadgame(loadfile);
			FoundingSmithy.loadgame(loadfile);
			FoundingGoldMine.loadgame(loadfile);
			FoundingHouse.loadgame(loadfile);
			loadfile.close();
			choice = 'N';
		}

//If the choice is no, the game starts over and allows the user to save to a file later
		if (choice == 'N')
		{

			while (select != 9)
			{
//Start Screen
				cout << "Lumber: " << FoundingCity.getLumber() << " Metal: " << FoundingCity.getMetal() << " Gold: " << FoundingCity.getGold() << endl;
				cout << "Please select an option." << endl;
				cout << "1.Produce Lumber \n2.Produce Metal \n3.Produce Gold "
					<< "\n4.Build Sawmill   Lumber:" << FoundingSawmill.getlumberPrice() << " Metal:" << FoundingSawmill.getmetalPrice() << " Gold:" << FoundingSawmill.getgoldPrice()
					<< "\n5.Build Smithy    Lumber:" << FoundingSmithy.getlumberPrice() << " Metal:" << FoundingSmithy.getmetalPrice() << " Gold:" << FoundingSmithy.getgoldPrice()
					<< "\n6.Build GoldMine  Lumber:" << FoundingGoldMine.getlumberPrice() << " Metal:" << FoundingGoldMine.getmetalPrice() << " Gold:" << FoundingGoldMine.getgoldPrice()
					<< "\n7.Build House     Lumber:" << FoundingHouse.getlumberPrice() << " Metal:" << FoundingHouse.getmetalPrice() << " Gold:" << FoundingHouse.getgoldPrice()
					<< "\n8.Stats \n9.Save and Exit" << endl;

//Input of their choice
				cin >> select;
				system("CLS");

//Switch statement for letting the user choose what they want to do
				switch (select)
				{
//Cheat Codes
				case 11235813:
					FoundingCity.cheatCode();
					break;

//Produce lumber
				case 1:
					FoundingCity.produceLumber(woodTimer, FoundingPeople, FoundingSawmill);
					break;
//Produce metal
				case 2:
					FoundingCity.produceMetal(metalTimer, FoundingPeople, FoundingSmithy);
					break;

//Produce gold
				case 3:
					FoundingCity.produceGold(goldTimer, FoundingPeople, FoundingGoldMine);
					break;

//Build the sawmill
				case 4:
					FoundingCity.buildSawmill(FoundingSawmill);
					break;

//Build the smithy
				case 5:
					FoundingCity.buildSmithy(FoundingSmithy);
					break;

//Build the goldmine
				case 6:
					FoundingCity.buildGoldMine(FoundingGoldMine);
					break;
				case 7:
//Build the house
					FoundingCity.buildHouse(FoundingHouse, FoundingPeople);
					break;

//Stats
				case 8:
					cout << "Number of People: " << FoundingCity.getPopulation(FoundingPeople)
						<< "\nNumber of Lumberjacks: " << FoundingPeople.getLumberjack()
						<< "\nNumber of Blacksmiths: " << FoundingPeople.getBlacksmith()
						<< "\nNumber of Merchants: " << FoundingPeople.getMerchant()
						<< "\nNumber of Sawmills: " << FoundingSawmill.getlumberModifier()
						<< "\nNumber of Smithys: " << FoundingSmithy.getmetalModifier()
						<< "\nNumber of Goldmines: " << FoundingGoldMine.getGoldModifier()
						<< "\nNumber of Houses: " << FoundingHouse.gethouseModifier() << endl;
					Sleep(5000);
					break;

//Saving the users game
				case 9:
					cout << "Name your saved game: ";
					cin >> savedgame;
					savefile.open(savedgame, ios::out);
					if (savefile.fail())
					{
						cout << "file has been corrupted" << endl;
						select = 10;
					}
//Writes all of the information to the file using the fstream object savefile
					savefile << FoundingCity.getLumber() << " " << FoundingCity.getMetal() << " " << FoundingCity.getGold() << " "
						<< FoundingPeople.getLumberjack() << " " << FoundingPeople.getBlacksmith() << " " << FoundingPeople.getMerchant() << " "
						<< FoundingSawmill.getlumberModifier() << " " << FoundingSmithy.getmetalModifier() << " " << FoundingGoldMine.getGoldModifier() << " "
						<< FoundingHouse.gethouseModifier() << endl;
					savefile.close();
					break;
				default:
					break;
				}
			}
		}
		else
		{
			cout << "Please enter: Y or N" << endl;
		}
	}

	return 0;
}