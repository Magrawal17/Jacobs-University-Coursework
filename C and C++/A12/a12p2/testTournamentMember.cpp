/*
 CH-230-A
 a12_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"
using namespace std;

int main()
{
    TournamentMember Example1("Mahiem","Agrawal","2000-04-15","Real Madrid",19);
    TournamentMember Example2("Arnav","Singh","2002-04-15","Werder Bremen",17);
    Example1.print(); 
    Example2.print();
    Example1.clocation("Germany");
    Example1.print(); 
    Example2.print();
}
