/*
CH-230-A
a10_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include "Complex.h"
#include <iostream>
using namespace  std;

Complex::Complex()
{
    real=0;
    imag=0;
}

Complex::Complex(float newreal,float newimag)
{
    real=newreal;
    imag=newimag;
}

void Complex::setimag(float newimag)
{
    imag=newimag;
}

void Complex::setreal(float newreal)
{
    real=newreal;
}

float Complex::getimag()
{
    return imag;
}

float Complex::getreal()
{
    return real;
}

void Complex::print()
{
   if (imag) {
		cout << noshowpos << real << showpos << imag << "i" << endl;
	} else {
		cout << noshowpos << real << showpos << endl;
	}
 }

Complex Complex::conjugate()
{
    Complex ans(real,-imag);
    return ans;
}

//Complex::Complex(Complex& b)
//{
    //real=b.real;
  //  imag=b.imag;
//}


Complex Complex::add(Complex b)
{
    Complex ans(real+b.real,imag+ b.imag);
    return ans;
}

Complex Complex::sub(Complex b)
{
    Complex ans(b.real-real,b.imag-imag);
    return ans;
}

Complex Complex::mult(Complex b)
{
    Complex ans(((real * b.real)-(imag*b.imag)),((real * b.imag)+(imag*b.real)));
    return ans;
}

Complex ::~ Complex () 
{
    //cout << "Executing destructor " << endl ;
}