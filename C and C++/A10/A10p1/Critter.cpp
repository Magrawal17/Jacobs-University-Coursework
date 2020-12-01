/*
CH-230-A
a10_p1.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"

using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::setWeight(double newweight){
	weight=newweight;
}
void Critter::setColor(std::string& newcolor){
    color=newcolor;
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
    cout << "My Weight is " << weight << ".Color is " << color << "." <<endl;
}

int Critter::getHunger() {
	return hunger;
}