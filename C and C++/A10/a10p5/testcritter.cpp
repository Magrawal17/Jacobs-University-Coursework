/*
CH-230-A
a10_p5.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter case1;
	Critter case2("Case2");
	Critter case3("Case3",23,9,33.6);
	Critter case4("Case4",212,9);
	case3.setHunger(2);
	case4.setHunger(2);
	case1.print();
	case2.print();
	case3.print();
	case4.print();
}