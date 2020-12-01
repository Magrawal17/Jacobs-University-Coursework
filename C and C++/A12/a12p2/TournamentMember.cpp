/*
 CH-230-A
 a12_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"
using namespace std;

string TournamentMember::location= "Nepal";


TournamentMember::TournamentMember(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage)
{
    cout<<"Parametric constructor being called"<<endl;
    strcpy(fname,nfname);
    strcpy(lname,nlname);
    strcpy(dob,ndob);
    teamname=nteamname;
    age=nage;
}

void TournamentMember::print() const
{
    cout<<"First Name: "<<fname<<endl;
    cout<<"Last Name: "<<lname<<endl;
    cout<<"Date of Birth: "<<dob<<endl;
    cout<<"Temname: "<<teamname<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<endl;
}

void TournamentMember::clocation(const string nlocation)
{
    location=nlocation;
}