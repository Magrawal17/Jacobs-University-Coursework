/*
 CH-231-A
 a2_p3.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include "WindGauge.h"
#include <iostream>
using namespace std;

int main()
{
    WindGauge A;

    A.currentWindSpeed(15);
    A.currentWindSpeed(16);
    A.currentWindSpeed(12);
    A.currentWindSpeed(15);
    A.currentWindSpeed(15);

    A.dump();
    cout<<endl;
    cout<<"Adding more values"<<endl;
    
    A.currentWindSpeed(16);
    A.currentWindSpeed(17);
    A.currentWindSpeed(16);
    A.currentWindSpeed(16);
    A.currentWindSpeed(20);
    A.currentWindSpeed(17);
    A.currentWindSpeed(16);
    A.currentWindSpeed(15);
    A.currentWindSpeed(16);
    A.currentWindSpeed(20);

    A.dump();

    return 0;
}