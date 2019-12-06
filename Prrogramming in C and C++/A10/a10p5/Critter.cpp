/*
CH-230-A
a10_p5.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"

using namespace std;
Critter::Critter()
{
	name="default_critter";
	hunger=0;
	height=5;
	boredom=0;
}
Critter::Critter(std::string newname)
{
	name=newname;
	hunger=0;
	height=5;
	boredom=0;

}

Critter::Critter(std::string newname,int newhunger,int newboredom,double newheight)
{
	name=newname;
	hunger=newhunger;
	boredom=newboredom;
	height=newheight;
}



void Critter::print() {
	cout<< "Name= " <<name<<endl;
	cout<< "Hunger= " <<hunger<<endl;
	cout<< "Boredom= " <<boredom<<endl;
	cout<< "Height= " <<height<<endl;
	cout<<endl;
}

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

