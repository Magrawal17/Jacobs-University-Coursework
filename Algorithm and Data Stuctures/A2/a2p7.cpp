/*
 CH-231-A
 a2_p7.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
using namespace std;

int main()
{
    ifstream in;
    map<string, string> data;
    in.open("data.txt", ios::in);

    string name;
    string birthday;

    while (!in.eof())
    {
        getline(in, name);
        getline(in, birthday);
        data[name] = birthday;
    }

    string input;
    cout << "Enter name of person" << endl;
    getline(cin, input);

    map<string, string>::iterator pos;
    pos = data.find(input);

    if (pos == data.end())
    {
        cout << "Name not found!" << endl;
    }
    else
    {
        cout << pos->first << "->" << pos->second << endl;
    }
    
    return 0;
}