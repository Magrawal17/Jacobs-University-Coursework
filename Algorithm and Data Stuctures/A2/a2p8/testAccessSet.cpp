/*
 CH-231-A
 a2_p6.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <set>
#include "Access.h"
using namespace std;

int main()
{
    Access A;
    A.activate(1234,1);
    A.activate(9999,5);
    A.activate(9876,9);
    
    unsigned int input;
    cout<<"Enter a code"<<endl;
    cin>>input;

    while (!A.isactive(input,5))
    {
        cout<<"Wrong code. Try again"<<endl;
        cin >> input;
    }
    cout<<"Door opened"<<endl;

    A.deactivate(input);
    A.deactivate(9999);
    A.activate(9999,8);
    A.activate(1111,7);

    cout<<"Enter a code"<<endl;
    cin>>input;
    while (!A.isactive(input,7))
    {
        cout<<"Wrong code. Try again"<<endl;
        cin >> input;
    }
    cout<<"Door opened"<<endl;
}