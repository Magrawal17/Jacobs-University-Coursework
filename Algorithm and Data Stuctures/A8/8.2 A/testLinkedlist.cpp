#include <iostream>
#include "Linkedlist.h"
using namespace std;

int main()
{
    Linkedlist temp;
    for (int i = 0; i < 5; i++)
    {
        temp.push(i);
    }
    cout<<"Before Reversing"<<endl;
    temp.print();
    temp.reverse();
    cout<<"After reversing"<<endl;
    temp.print();
}