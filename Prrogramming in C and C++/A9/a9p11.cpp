/*
CH-230-A
a9_p11.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    string temp=s;
    int count=0;
    for (unsigned int i = (s.length()-1); i >= 0; i--)
    {
        count=count+1;
    }
    if (temp==s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    Start:while(1)
    {
        cout<<"Enter a word"<<endl;
        cin>>s;
        if (s=="exit")
        {
            cout<<"Thank you for trying"<<endl;
            exit(1);
        }
        if (isPalindrome(s)==true)
        {
            cout<<"Word is Pallindrome"<<endl;
        }   
        else
        {
            cout<<"Word is not pallindrome"<<endl;
        }
        cout<<"Do you want to play again, Yes or No"<<endl;
        string ans;
        cin>>ans;
        if (ans=="Yes")
        {
            goto Start;
        }
        else
        {
            break;
        }
    }
    return 0;
}