
/*
CH-230-A
a13_p6.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include "Matrix.h"
#include <iostream>
using namespace std;

Vector Matrix::operator*(Vector &obj)
{
    if (this->column == obj.getsize())
    {
        Vector ans(this->row);
        int temp;
        for (int i = 0; i < this->row; i++)
        {
            temp = 0;
            for (int j = 0; j < this->column; j++)
            {
                temp = temp + (this->components[i][j] * obj.getcomponent()[j]); //
            }
            ans.setcomponent(i, temp);
        }
        return ans;
    }
    else
    {
        cout << "Not possible" << endl;
        return obj;
    }
}


istream &operator>>(istream &in, Matrix &obj)
{
    in >> obj.row;
    in >> obj.column;

    obj.components = new double*[obj.row];
    for (int i = 0; i < obj.row; i++)
    {
        obj.components[i] = new double [obj.column];
    }

    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.column; j++)
        {
            in >> obj.components[i][j];
        }
    }
    return in;
}


Matrix::Matrix()
{
    row = 0;
    column = 0;
}

Matrix::~Matrix()
{
}

ostream &operator<<(ostream &out, const Matrix &obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.column; j++)
        {
            out << obj.components[i][j] << " ";
        }
        out << endl;
    }
    return out;
}


Vector Vector::operator*(Matrix &obj)
{
    if (obj.getrow() == this->size)
    {
        Vector ans(obj.getrow());
        int temp;
        for (int i = 0; i < obj.getrow(); i++)
        {
            temp = 0;
            for (int j = 0; j < obj.getcolumn(); j++)
            {
                temp = temp + (obj.getcomponents()[j][i] * this->components[j]); //
            }
            ans.setcomponent(i, temp);
        }
        return ans;
    }
    else
    {
        cout << "Not possible" << endl;
        return 0;
    }
}