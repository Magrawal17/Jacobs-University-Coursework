/*
CH-230-A
a10_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "Complex.h"

using namespace std;

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(float nreal, float nimag)
{
    real = nreal;
    imag = nimag;
}

Complex::Complex(Complex &obj)
{

    real = obj.real;
    imag = obj.imag;
}

void Complex::setreal(float nreal)
{
    real = nreal;
}

void Complex::setimag(float nimag)
{
    imag = nimag;
}

float Complex::getreal()
{
    return real;
}

float Complex::getimag()
{
    return imag;
}

Complex::~Complex()
{

}

Complex Complex::operator *(Complex &obj)
{
    Complex ans;
    ans.real = real * obj.real - imag * obj.imag;
    ans.imag = real * obj.imag + imag * obj.real;
    return ans;
}

Complex Complex::operator +(Complex &obj)
{
    Complex ans;
    ans.real = real + obj.real;
    ans.imag = imag + obj.imag;
    return ans;
}

Complex Complex::operator -(Complex &obj)
{
    Complex ans;
    ans.real = real - obj.real;
    ans.imag = imag - obj.imag;
    return ans;
}

Complex Complex::operator =(const Complex &obj)
{
    real = obj.real;
    imag = obj.imag;
    return *this;
}


ostream &operator<<(ostream &out, const Complex &obj)
{
    out << obj.real << "+" << obj.imag << "i" << endl; 
    return out;
}

istream &operator>>(istream &in, Complex &obj)
{
    in >> obj.real;
    in >> obj.imag;
    return in;
}