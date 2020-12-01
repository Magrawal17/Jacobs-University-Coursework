/*
CH-230-A
a10_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include "Person.h"
#include <iostream>


using namespace std;

void Person::setname(const std::string& newname)
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

std::string Person::getname () const
{
    return name;
}

int Person::getage () const
{
    return age;
}

float Person::getheight() const
{
    return height;
}

double Person::getweight() const
{
    return weight;
}

void Person::print() const
{
    cout<<"The name is " << name << " .My age is  " << age;
    cout<<" .Height is " << height << ". Weight is " << weight <<endl;
}

Person::Person()
{
    cout<<"Empty Construcotr being called"<<std::endl;
    name="";
    age=0;
    height=0;
    weight=0;
}

Person::Person(const std::string& newname,const int newage,const double newheight,const float newweight)
{
    cout<<"Parametric Construcotr being called"<<std::endl;
    name=newname;
    age=newage;
    height=newheight;
    weight=newweight;
}

Person::Person(Person& b)
{
    cout<<"Copy Construcotr being called"<<std::endl; 
    name=b.name;
    age=b.age;
    height=b.height;
    weight=b.weight;
}
