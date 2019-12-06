/*
 CH-230-A
 a12_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"
using namespace std;

int main()
{
    Player Example1("Mahiem","Agrawal","2000-04-15","Real Madrid",19,7,"DF",40,"Right");
    Player Example2("Arnav","Singh","2002-04-15","Werder Bremen",17,12,"MID",1,"Right");
    Player Example3("Joe","Sakurai","2000-04-12","Japan",11,99,"GK",0,"Left");
    Example1.print(); 
    Example2.print();
    Example3.print(); 
    Example3.increment(2);
    Player::clocation("Hamburg");
    Example1.print(); 
    Example2.print();
    Example3.print(); 
}
