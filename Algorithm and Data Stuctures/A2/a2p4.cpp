/*
 CH-231-A
 a2_p4.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> num;
    for (int i = 1; i < 31; i++)
    {
        num.push_back(i);
    }
    num.push_back(5);
    reverse(num.begin(), num.end());
    vector<int>::iterator pos;
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;
    replace(num.begin(), num.end(), 5, 129);
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;
    return 0;
}