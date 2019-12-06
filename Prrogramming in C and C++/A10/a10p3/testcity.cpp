/*
CH-230-A
a10_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "City.h"

int main()
{
    City bremen,paris,london;
    bremen.setname("bremen");
    paris.setname("paris");
    london.setname("london");
    
    bremen.setinhab(1000);
    paris.setinhab(102);
    london.setinhab(232);
    
    bremen.setmayor("Mahiem");
    paris.setmayor("Mahiem1");
    london.setmayor("Mahiem2");
    
    bremen.setarea(212.2);
    paris.setarea(32.3);
    london.setarea(11.3);

    bremen.print();
    paris.print();
    london.print();
    return 0;
}