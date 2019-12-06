/*
CH-230-A
a10_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a;
    Complex b;
    ifstream in1("in1.txt");
    in1 >> a;
    ifstream in2("in2.txt");
    in2 >> b;
    cout<<"First complex number"<<endl;
    cout<<a;
    cout<<"Second complex number"<<endl;
    cout<<b;
    ofstream out("output.txt");
    cout<<"Addition of the complex numbers"<<endl;
    out<<"Addition of the complex numbers"<<endl;
    cout<<a+b;
    out<<a+b;
    cout<<"Difference of the complex numbers"<<endl;
    out<<"Difference of the complex numbers"<<endl;
    cout<<a-b;
    out<<a-b;
    cout<<"Multiplication of the complex numbers"<<endl;
    out<<"Multiplication of the complex numbers"<<endl;
    cout<<a*b;
    out<<a*b;
    return 0;
}