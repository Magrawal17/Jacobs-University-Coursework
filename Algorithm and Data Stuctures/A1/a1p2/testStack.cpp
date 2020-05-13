/*
 CH-231-A
 a1_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> item;

    cout<<"Pushing 10 items"<<endl;
    for (int i = 0; i < 11; i++)        //intentionaly have tried adding 11 elements
    {
        item.push(i);
    }
    
    Stack<int> itemcpy(item);
    cout<<"Printing using the copy constructor"<<endl;
    itemcpy.print();
    
    cout<<"Setting size to 20 then adding and popping elements"<<endl;
    Stack<double> item1(20);
    for (int i = 0; i < 20; i++)
    {
        item1.push(i*1.5);
    }
    item1.print();
    cout<<"Current number of elements: "<<item1.getNumEntries()<<endl;
    cout<<"Data at the top of stack: "<<item1.back()<<endl;
    for (int i = 0; i < 21; i++)            //intentionally popping out 21 elements
    {
        double out;
        item1.pop(out);
        cout<<out<<" ";
    }
    cout<<endl;

}