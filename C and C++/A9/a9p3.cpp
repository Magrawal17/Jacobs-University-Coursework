/*
CH-230-A
a9_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>

float abs(float a)
{
    if (a>=0)
    {
        return a;
    }
    else
    {
        
        return (-a);
    }
}

int main()
{
    float x;
    std::cin>>x;
    std::cout<<"The absolute value is "<<abs(x)<<std::endl;
    return 0;
}