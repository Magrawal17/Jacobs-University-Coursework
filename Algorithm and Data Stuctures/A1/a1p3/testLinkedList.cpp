/*
 CH-231-A
 a1_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;


int main()
{
    Linkedlist<int> list;

    list.addend(6);
    list.addstart(4);
    list.addstart(5);
    list.addend(7);
    list.addstart(3);
    list.addstart(2);
    list.addstart(1);
    list.addend(8);
    
    cout << "The list has Items: "<< list.getSize() << endl;
    cout << "Front Item: " << list.startitem() << endl;
    cout << "Last Item: " << list.lastitem() << endl;
    cout<<endl;

    cout<<"Adding at the front and end"<<endl;
    list.addstart(0);
    list.addend(9);
    cout << "The list has Items: "<< list.getSize() << endl;
    cout<<endl;
  
    
    cout<<"Deleting Front Item: "<< list.deletestart() << endl;
    cout << "Deleting Last Item: " << list.deleteend() << endl;
    cout << "The list has Items: "<< list.getSize() << endl;
    cout << "Front Item: " << list.startitem() << endl;
    cout << "Last Item: " << list.lastitem() << endl;
    cout<<endl;
  
    return 0;
}
