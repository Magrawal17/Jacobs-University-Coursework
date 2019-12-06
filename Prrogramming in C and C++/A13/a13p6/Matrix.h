/*
CH-230-A
a13_p6.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/
#include <iostream>
#include "Vector.h"
using namespace std;

class Matrix
{
private:
  int row;
  int column;
  double **components;

public:
    Matrix();
    ~Matrix();
    int getrow(){return row;}
    int getcolumn(){return column;}
    double **getcomponents(){return components;}
    friend ostream &operator<<(ostream &, const Matrix &);
    friend istream &operator>>(istream &, Matrix &);
    Vector operator * (Vector &);
};