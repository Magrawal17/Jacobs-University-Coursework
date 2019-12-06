#include <iostream>
#include "Shapes.h"
using namespace std;

int main()
{
    Hexagon one("Hex1",1,1,9,"Blue");
    Hexagon two("Hex2",0,0,15,"Green");
    Hexagon three(two);
    one.printName();
    cout<<"Area: "<<one.area()<<endl;
    cout<<"Perimeter: "<<one.perimeter()<<endl;
    two.printName();
    cout<<"Area: "<<two.area()<<endl;
    cout<<"Perimeter: "<<two.perimeter()<<endl;
    three.printName();
    cout<<"Area: "<<three.area()<<endl;
    cout<<"Perimeter: "<<three.perimeter()<<endl;
    return 0;
}