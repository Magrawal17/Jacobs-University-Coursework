/*
CH-230-A
a9_p6.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include <iostream>
using namespace std;

int main()
{
    string name_user;
    cout<<"Enter your name"<<endl;
    cin>>name_user;
    int count=0;
    cout<<"Welcome "<<name_user<<endl;
    cout<<"Now guess the number between 1 and 100"<<endl;
    int n,randomNumber=0;
    srand (static_cast <unsigned int>(time (0)));
    randomNumber = rand () ;
    randomNumber = ( randomNumber % 100) + 1;
    while(1)
    {
        cin>>n;
        count=count +1;
        if (n>randomNumber)
        {
            cout<<"Wrong Try! Guess a lower number"<<endl;
        }
        else if (n<randomNumber)
        {
            cout<<"Wrong Try! Guess a higher number"<<endl;
        }
        else if( n==randomNumber)
        {
            break;
        }
    }
    cout<<"Congratualtions you solved the problem in "<<count<<" tries"<<endl;
    return 0;
}
