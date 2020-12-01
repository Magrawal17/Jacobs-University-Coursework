#include "Shapes.h"
#include<iostream>
using namespace std;

int main(int argc, char** argv) 
{
  
  Circle c("Circle", 3, 4, 7);
  RegularPolygon r("TRIANGLE", 1, 1, 3);
  Rectangle r1("Rectangle",0,0,10,5);
  Square s("Square",0,0,5);

  c.printName(); 
  cout<<"Area: "<<c.area()<<endl;
  cout<<"Perimeter: "<<c.perimeter()<<endl;
  cout<<""<<endl;

  r1.printName();
  cout<<"Area: "<<r1.area()<<endl;
  cout<<"Perimeter: "<<r1.perimeter()<<endl;
  cout<<""<<endl;

  s.printName();
  cout<<"Area: "<<s.area()<<endl;
  cout<<"Perimeter: "<<s.perimeter()<<endl;
  cout<<""<<endl;

}