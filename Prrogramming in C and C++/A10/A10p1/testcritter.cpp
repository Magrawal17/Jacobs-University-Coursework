/*
CH-230-A
a10_p1.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c;

	string name;
	int hunger;
    int weight;
    string color;
 
	cout << endl << "Please enter data: " << endl;
	cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(cin, name);
	c.setName(name);
	//c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);
    cout<<"Weight: ";
    cin >> weight;
    c.setWeight(weight);
	cin.get();
    cout<<"Color: ";
    getline(cin, color);
    c.setColor(color);

    

	cout << "You have created:" << endl;
	c.print();
        return 0;
}