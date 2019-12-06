/*
CH-230-A
a13_p6.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <string>
#include "Matrix.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    string name;
    ifstream file1;
    ifstream file2;
    ofstream file3;
    cout<<"Enter the name of file which has Matrix"<<endl;
    cin>>name;
    file1.open(name,ios::in);
    Matrix A;
    file1>>A;
    cout<<"Matrix entered is"<<endl;
    cout<<A;
    cout<<"Enter the name of file which has Vector"<<endl;
    cin>>name;
    file2.open(name,ios::in);
    Vector B;
    file2>>B;
    cout<<"Vector entered is"<<endl;
    cout<<B;
    
    
    cout<<"Enter the name in which to store the files"<<endl;
    cin>>name;
    file3.open(name,ios::out);
    
    cout<<"Multiplication of Matrix and Vector is"<<endl;
    file3<<"Multiplication of Matrix and Vector is"<<endl;
    
    cout<<A*B;
    file3<<A*B;

    cout<<"Multiplication of Vector and Matrix is"<<endl;
    file3<<"Multiplication of Vector and Matrix is"<<endl;

    cout<<B*A;
    file3<<B*A;
    return 0;

    


    
}
