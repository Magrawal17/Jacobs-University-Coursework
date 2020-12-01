/*
CH-230-A
a10_p2.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"

using namespace std;

void Critter::setName(string& newname) 
{
	name = newname;
}

void Critter::setHunger(int newhunger) 
{
	hunger = newhunger;
}

void Critter::setBoredom(int newboredom)
{
	boredom=newboredom;
}

void Critter::setHeight(double newheight)
{
	height=newheight;
}
  

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
    cout << "My Boredom is " << boredom << ".Height is " << height << "." <<endl;
}

std::string Critter::getname()
{
	return name;
}

int Critter::getHunger() 
{
	return hunger;
}

int Critter::getBoredom() 
{
	return boredom;
}

double Critter::getHeight() 
{
	return height;
}

