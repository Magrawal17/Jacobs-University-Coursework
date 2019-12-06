/*
CH-230-A
a10_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include "City.h"
#include <iostream>


using namespace std;

void City::setname(std::string newname)
{
    name=newname;
}

void City::setinhab(int newinhab)
{
    inhab=newinhab;
}
   
 void City::setmayor(std::string newmayor)
 {
     mayor=newmayor;
 }

void City::setarea(double newarea)
{
    area=newarea;
}

std::string City::getname()
{
    return name;
}

int City::getinhab()
{
    return inhab;
}

std::string City::getmayor()
{
    return mayor;
}

double City::getarea()
{
    return area;
}

void City::print()
{
    cout<<"The name is " << name << " .Number of inhabitants " << inhab;
    cout<<" . Mayor is " << mayor << ". Area is " << area <<endl;
}
