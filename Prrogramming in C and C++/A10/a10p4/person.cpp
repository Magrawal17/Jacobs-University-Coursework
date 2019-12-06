/*
CH-230-A
a10_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include "Person.h"
#include <iostream>


using namespace std;

void Person::setname(const std::string *newname)
{
    name=newname;
}

void Person::setage(const int newage)
{
    age=newage;
}
   
 void Person::setheight(const double newheight)
 {
     height=newheight;
 }

void Person::setweight(const float newweight)
{
    weight=newweight;
}

std::string Person::getname()
{
    return name;
}

int Person::getage()
{
    return age;
}

float Person::getheight()
{
    return height;
}

double Person::getweight()
{
    return weight;
}

void Person::print()
{
    cout<<"The name is " << name << " .My age is  " << age;
    cout<<" .Height is " << height << ". Weight is " << weight <<endl;
}
