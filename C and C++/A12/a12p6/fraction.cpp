/*
 CH-230-A
 a12_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b)
{
	int tmp_gcd = 1;

	// Implement GCD of two numbers;

	return tmp_gcd;
}

int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);

}


std::ostream& operator <<(std::ostream& out ,const Fraction &obj)
{
	out << obj.num << "/" << obj.den <<std::endl;
	return out;
}

std::istream& operator >>(std::istream& in , Fraction &obj)
{
	int temp;
	std::cout<<"Enter Numerator"<<std::endl;
	in>>obj.num;
	do
	{
		std::cout<<"Enter Denominator"<<std::endl;
		in>>temp;
	}while (temp==0);
	obj.den=temp;
	return in;
}

Fraction Fraction::operator *(Fraction& obj)
{
	Fraction ans(this->num*obj.num,this->den*obj.den);
	return ans;

}

Fraction Fraction::operator /(Fraction& obj)
{
	Fraction ans(this->num*obj.den,this->den*obj.num);
	return ans;
}