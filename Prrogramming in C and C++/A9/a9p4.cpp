/*
CH-230-A
a9_p4.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include <iostream>
using namespace std;

int mycount(int a,int b);
int mycount(char a,string b);

int main ()
{
    cout<<mycount(7,3)<<endl;
    cout<<mycount('i',"this is a string")<<endl;
    return 0;
} 
  

int mycount(int a, int b){
    return b-a;
}


int mycount(char a,string b)
{
    int count=0;
    for (unsigned int i=0; i< b.length();i++)
    {
        if (b[i]==a)
        {
            count=count +1;
        }
    }
    return count;
}
