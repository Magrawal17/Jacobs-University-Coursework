/*
CH-230-A
a10_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "Person.h"

int main()
{
    Person p1,p2,p3;

    p1.setname("p1");
    p2.setname("p2");
    p3.setname("p3");
    
    p1.setage(1);
    p2.setage(12);
    p3.setage(123);
    
    p1.setheight(6.54444);
    p2.setheight(324.2343);
    p3.setheight(34243.23432);
    
    p1.setweight(212.2);
    p2.setweight(32.3);
    p3.setweight(11.3);

    p1.print();
    p2.print();
    p3.print();

    Person p4(p1);
    Person p5("p5",1234,3232.2,232);
    p4.print();
    p5.print();
    return 0;
}