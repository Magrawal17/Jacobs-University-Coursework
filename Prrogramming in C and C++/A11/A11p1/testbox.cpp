/*
CH-230-A
a11_p1.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of boxes"<<endl;
    cin>>n;

    Box *list;
    list=new Box[2*n]; 
    
    double height;
    double width;
    double depth;

    for (int i = 0; i < n; i++) 
    {
        cout<<"Box number " <<i <<endl;
        cout<<"Height"<<endl;
        cin>>height;
        list[i].setheight(height);
        cout<<"Width"<<endl;
        cin>>width;
        list[i].setwidth(width);
        cout<<"Depth"<<endl;
        cin>>depth;
        list[i].setdepth(depth);
    }

    for (int i = n; i < n*2; i++)
    {
       (Box(list[i-n]));
    }

    for (int i = 0; i < n*2; i++)
    {
        list[i].vprint();
    }
    
     delete [] list;

    return 0;    
}