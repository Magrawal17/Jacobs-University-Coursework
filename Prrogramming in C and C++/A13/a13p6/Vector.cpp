/*
CH-230-A
a13_p6.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include "Vector.h"

#include <iostream>
using namespace std;

Vector::Vector()
{
    size = 0;
}

Vector::~Vector()
{
}

Vector::Vector(int nsize)
{
    size = nsize;
    components = new double[size];
}

double *Vector::getcomponent()
{
    return components;
}

void Vector::setcomponent(int pos, double value)
{
    components[pos] = value;
}

ostream &operator<<(ostream &out, const Vector &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        out << obj.components[i] << " ";
    }
    out << endl;
    return out;
}

istream &operator>>(istream &in, Vector &obj)
{
    in >> obj.size;
    obj.components = new double[obj.size];
    for (int i = 0; i < obj.size; i++)
    {
        in >> obj.components[i];
    }
    return in;
}





