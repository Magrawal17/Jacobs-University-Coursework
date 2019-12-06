/*
 CH-230-A
 a13_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout<<"Enter the file name"<<endl;
    string name;
    cin>>name;
    ifstream in(name);
    int pos= name.find(".");
    string output=name.insert(pos,"_copy");
    ofstream out(output);
    char temp[50];
    while (in.eof() == 0)
    {
        in.getline(temp,256);
        out<<temp<<endl;
    }
    
    in.close();
    out.close();
    return 0;
}