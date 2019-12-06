/*
 CH-230-A
 a12_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"
using namespace std;

string TournamentMember::location= "Nepal";

TournamentMember::TournamentMember(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage)
{
   // cout<<"Parametric constructor being called"<<endl;
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

bool Referee::addToYellowCardList(Player *p)
{
    for (int i = 0; i < yellowCardCount; i++)
    {
        if (p==yellowCardList[i])
        {
            yellowCardList[yellowCardCount]=NULL;
            yellowCardCount=yellowCardCount-1;
            addToRedCardList(p);
            return false;// Hard to determine whether we can consider this true or false
        }
    }
    if (yellowCardCount==40)
    {
        cout<<"Adding unssucesful"<<endl;
        return false;
    }
    else
    {
        yellowCardList[yellowCardCount]=p;
        yellowCardCount=yellowCardCount+1;
        return true;
    }
}

bool Referee::addToRedCardList(Player *p)
{
    for (int i = 0; i < redCardCount; i++)
    {
        if (p==redCardList[i])
        {
            return false;
        }
    }
    redCardList[redCardCount]=p;
    redCardCount=redCardCount+1;
    
    return true;
}
void Referee::print() const
{
    cout<<"Yellow Card Count: "<<yellowCardCount<<endl;
    cout<<"Name of Players with yellow card"<<endl;
    for (int i = 0; i < yellowCardCount; i++)
    {
       cout<<yellowCardList[i]->getfname()<<endl;
    }
    cout<<"Red Card Count: "<<redCardCount<<endl;
    cout<<"Name of Players with Red card"<<endl;
    for (int i = 0; i < redCardCount; i++)
    {
       cout<<redCardList[i]->getfname()<<endl;
    }
}