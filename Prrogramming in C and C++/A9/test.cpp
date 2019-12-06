#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
int main()
{
    string str1;
    string concat;
    bool test=true; // initialising the bool variable
    while(test)
    {
         // concatenating each string.
        getline(cin,str1);
        
        if(str1=="quit") // condition for exiting loop
        {
           test=false;
        }else
        {
           
        concat=concat+str1;
        }
        
    }
    cout<<concat<<endl; // printing the concatenated string
    return 0;
}