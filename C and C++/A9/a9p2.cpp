/*
CH-230-A
a9_p2.c
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


#include <iostream>
using namespace std;

int main()
{
    int n;
    double x;
    string s;
    cout <<"Enter integer ";
    cin >> n;
    cout <<"Enter double ";
    cin >> x;
    cout <<"E2nter string ";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cout << s << ":" << x << endl;
    }
    return 0;
}

