/*
 CH-230-A
 a12_p3.c
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

 Player::Player(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage,int nnumber,string nposition,int ngoals,string nfoot)
 :TournamentMember(nfname,nlname,ndob,nteamname,nage)
 {
     number=nnumber;
     position=nposition;
     goals=ngoals;
     foot=nfoot;
 }

 void Player::print() const
 {
    cout<<"First Name: "<<getfname()<<endl;
    cout<<"Last Name: "<<getlname()<<endl;
    cout<<"Date of Birth: "<<getdob()<<endl;
    cout<<"Temname: "<<getteamname()<<endl;
    cout<<"Age: "<<getage()<<endl;
    cout<<"Location: "<<getlocation()<<endl;
    cout<<"Number: "<<number<<endl;
    cout<<"Position "<<position<<endl;
    cout<<"Goals scored: "<<goals<<endl;
    cout<<"Feet: "<<foot<<endl;
    cout<<endl;
 }

void Player::increment(int num)
{
    goals=goals+num;
}