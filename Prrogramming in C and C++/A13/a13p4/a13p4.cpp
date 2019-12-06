/*
CH-230-A
a13_p4.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include<iostream>
using namespace std;
 
class A
{
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x; }
};
 
class B:  public virtual A //virtual added here 
{
public:
  B()  { setX(10);
  cout<<"B constructor"<<endl;}
};
 
class C:  public virtual A  // virtual added here
{
public:
  C()  
  {
     setX(20); 
     cout<<"C constructor"<<endl;}
};
 
class D: public C, public B {
  public:
  //  D():  C(),B(){};
};
 
//there is an error in this program when virtual is not added as when print
//method is called the compiler is not sure which method it is talking about.
//it can either be one of C or one of B therefore having the inheritence virtual 
//fixes this problm.Ambiguty problem fixed.


int main()
{
    D d;
    d.print();
    return 0;
}