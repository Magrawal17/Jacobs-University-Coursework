/*
CH-230-A
a10_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex a(1,2);
    Complex b(3,-5);
    cout<<"First complex number"<<endl;
    a.print();
    cout<<"Second complex number"<<endl;
    b.print();
    cout<<"Conjugate of the first complex number"<<endl;
    Complex conjugate;
    conjugate = a.conjugate();
    conjugate.print();
    cout<<"Addition of the complex numbers"<<endl;
    Complex add;
    add =a.add(b); 
    add.print();
    cout<<"Diffrence of the complex numbers"<<endl;
    Complex sub;
    sub =a.sub(b); 
    sub.print();
    cout<<"Multiplication of the complex numbers"<<endl;
    Complex mult;
    mult =a.mult(b); 
    mult.print();
};