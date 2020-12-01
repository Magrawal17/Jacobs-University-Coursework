/*
 CH-230-A
 a12_p7.c
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
	if (a == 0) return b; 
    if (b == 0) return a;  
    if (a == b) return a; 
   	if (a > b) 
	{
        return gcd(a-b, b); 
	}
	else
	{
		return gcd(a, b-a); 	
	}
	
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

Fraction operator +(Fraction& obj1,Fraction&obj2)
{
	Fraction ans;
	//ans.num=((this->num*lcm(this->den,obj.den))/this->den)+((obj.num*lcm(this->den,obj.den))/obj.den);
//	ans.den=lcm(this->den,obj.den);
	ans.num=obj1.num+obj2.num;
	ans.den=obj1.den+obj2.den;
	return ans;
}
Fraction Fraction::operator -(Fraction& obj)
{
	Fraction ans;
	ans.num=((this->num*lcm(this->den,obj.den))/this->den)-((obj.num*lcm(this->den,obj.den))/obj.den);
	ans.den=lcm(this->den,obj.den);
	return ans;
}

Fraction& Fraction::operator =(const Fraction&obj)
{
	this->num=obj.num;
	this->den=obj.den;
	return *this;
}

bool Fraction::operator <(const Fraction&obj)
{
	double temp1=(double)(this->num)/(double)(this->den);
	double temp2=(double)(obj.num)/(double)(obj.den);
	if (temp1 <temp2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator >(const Fraction&obj)
{
	double temp1=(double)(this->num)/(double)(this->den);
	double temp2=(double)(obj.num)/(double)(obj.den);
	if (temp1 >temp2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


