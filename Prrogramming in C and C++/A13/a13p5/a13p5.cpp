/*
CH-230-A
a13_p4.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
using namespace std;

class A
{
  int x;

public:
  A() { x = 0; }; //empty constructor for A
  A(int i) { x = i; }
  void print() { cout << x; }
};

class B : virtual public A
{
public:
  B() : A(10) {}
};

class C : virtual public A
{
public:
  C() : A(10) {}
};

class D : public B, public C
{
  public:
  D():B(),C(){};
};

int main()
{
  D d;
  d.print();
  return 0;
}

//here i have defined an empty constructor for A as
// D derives its propety form class A thorough virtual. Therefore
//without the empty construcor it can not be initlaized.