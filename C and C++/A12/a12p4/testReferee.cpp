/*
 CH-230-A
 a12_p4.c
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
    Player::clocation("Hamburg");
    Referee Example4("Howard","Web","2001-02-12","NA",54);
    
    Example4.addToYellowCardList(&Example1);
    Example4.addToYellowCardList(&Example1);
    Example4.addToYellowCardList(&Example3);

    Example4.addToRedCardList(&Example2);
    Example4.addToRedCardList(&Example2);
    
    Example4.print();
}
