/*
CH-230-A
a13_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    string *names;
    int n;
    cout << "Enter number of files you want" << endl;
    cin >> n;
    names = new string[n];
    for (int i = 0; i < n; i++){
    cout << "Enter the names of the files" << endl;
    cin >> names[i];
    }
    ifstream in;
    ofstream out("concatn.txt");
    char temp[256];
    for (int i = 0; i < n; i++){
        in.open(names[i], ios::binary);
        while (in.get(temp, 256))
        {
            in.get();
            out << temp << endl;
        }
        out << endl;
        in.close();
        }
    return 0;
}