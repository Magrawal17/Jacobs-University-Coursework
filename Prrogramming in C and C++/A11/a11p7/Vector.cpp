#include "Vector.h"
#include <iostream>
#include <cmath>
using namespace std;

Vector::Vector()
{
    size=0;
    components= new double [0];
}

Vector::Vector(Vector& b)
{
    size=b.size;
    components=b.components;
}

Vector::~Vector()
{
    //delete []components;
    //Program runs into error it would be grateful if you told me the fix for this.
    
}

Vector::Vector(int newsize,double*& newcomponents)
{
    size=newsize;
    components=newcomponents;    
}

void Vector::setSize(int newsize)
{
    size=newsize;   
}

void Vector::setComponent(double*& newcomponents)
{
    components=newcomponents;    
}

double* Vector::getComponents() const
{
    return components;
}

int Vector::getSize() const
{
    return size;
}

void Vector::printvector()
{
    for(int i=0;i<size;i++)
    {
            cout<<components[i]<<" ";
    }
    cout<<endl;
}

double Vector::norm() const
{
    double ans;
    for (int i = 0; i < size; i++)
    {
        ans=ans + pow(2,components[i]);
    }
    ans=sqrt(ans);
    return ans;
}

Vector Vector::sum(const Vector& b) const
{
    double* temp;
    temp=new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i]=components[i]+b.components[i];
    }
    Vector ans(size,temp);
    return ans;
}

Vector Vector::diff(const Vector& b) const
{
    double* temp;
    temp=new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i]=components[i]-b.components[i];
    }
    Vector ans(size,temp);
    return ans;
}

double Vector::scalar(Vector& b)const
{
    
   double ans;
   for (int i = 0; i < size; i++)
   {
       ans=ans+(components[i]*b.components[i]);
   }
    return ans;
}