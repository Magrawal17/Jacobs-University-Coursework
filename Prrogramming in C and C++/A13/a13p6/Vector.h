/*
CH-230-A
a13_p6.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/
#include <iostream>
using namespace std;
class Matrix;

class Vector
{
private:
  int size;
  double *components;

public:
  Vector();
  ~Vector();
  Vector(int);
  void setcomponent(int, double);
  double *getcomponent();
  int getsize() { return size; }

  friend istream &operator>>(istream &in, Vector &obj);
  friend ostream &operator<<(ostream &out, const Vector &obj);
  Vector operator*(Matrix &);
};
