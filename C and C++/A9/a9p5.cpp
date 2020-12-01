/*
CH-230-A
a9_p5.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include <iostream>
using namespace std;

int main()
{
    bool ans=false;
    string str;
    string concat;
    do
    {
        cin>>str;
        if (str=="quit")
        {
             ans=true;
        }
        else 
        {
             concat=concat + str;
        }   
    } while (ans==false);
    cout<<concat<<endl;
    return 0;
}