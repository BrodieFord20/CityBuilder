//Header file for Building
#ifndef Building_H
#define Building_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Building
{

public:
//Resource variables
	int lumberPrice;
	int metalPrice;
	int goldPrice;

//Calling of functions to get the resource variables
	int getlumberPrice();
	int getmetalPrice();
	int getgoldPrice();
	
};

#endif
