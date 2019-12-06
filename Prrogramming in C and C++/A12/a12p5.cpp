/*
 CH-230-A
 a12_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <iostream>
#include <string>
using namespace std;

string randomcolr(string colors[])
{
    int die;    
    int randomNumber;  
    randomNumber = rand();
    die = (randomNumber % 4);
    return colors[die];
 
}

int main()
{
    string colors[4]={"RED","BLACK","VIOLET","BLUE"};
    for (int i = 0; i < 15; i++)
    {
        cout<<randomcolr(colors)<<endl;
    }
    return 0;
}



