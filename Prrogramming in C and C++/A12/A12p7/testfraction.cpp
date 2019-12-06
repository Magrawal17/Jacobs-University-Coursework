/*
 CH-230-A
 a12_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
	Fraction a,b;
	cout<<"Enter Fraction A"<<endl;
	cin>>a;
	cout<<"Enter Fraction B"<<endl;
	cin>>b;
	cout<<"Multiplication of the numbers are"<<endl;
	cout<<a*b;
	cout<<"Division of the numbers are"<<endl;
	cout<<a/b;
	cout<<"Addition of the numbers are"<<endl;
	Fraction c=a+b;
	cout<<c;
	cout<<"Subtraction of the numbers are"<<endl;
	Fraction d=a-b;
	cout<<d;
	if (a>b)
	{
		cout<<"A is greater "<<endl;
	}
	else
	{
		cout<<"B is greater"<<endl;
	}
	if (a<b)
	{
		cout<<"A is smaller"<<endl;
	}
	else
	{
		cout<<"B is smaller"<<endl;
	}
	return 0;
}
