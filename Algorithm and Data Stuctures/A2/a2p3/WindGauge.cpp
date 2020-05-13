/*
 CH-231-A
 a2_p3.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <algorithm> 
#include <numeric> 
#include "WindGauge.h"
using namespace std;

WindGauge::WindGauge(int period)
{
    this->period = period;
}

void WindGauge::currentWindSpeed(int speed)
{
    if (this->WG.size() >= this->period)
    {
        this->WG.pop_back();
    }
    this->WG.push_front(speed);
}

void WindGauge::dump()
{
    cout<<"Lowest is "<<this->lowest()<<endl;
    cout<<"Average is "<<this->average()<<endl;
    cout<<"Highest is "<<this->highest()<<endl;
}

int WindGauge::highest() const
{
    return *max_element(this->WG.begin(),this->WG.end());
}

int WindGauge::lowest() const
{
    return *min_element(this->WG.begin(),this->WG.end());
}

int WindGauge::average() const
{
    float sum= accumulate(this->WG.begin(),this->WG.end(),0);
    return (sum/this->WG.size());
}

