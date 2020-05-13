/*
 CH-231-A
 a2_p2.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    deque<float> A;
    float input;
    cin >> input;
    while (input != 0)
    {
        if (input > 0)
        {
            A.push_back(input);
        }
        else
        {
            A.push_front(input);
        }
        cin >> input;
    }

    deque<float>::iterator itrA;

    cout << "Deque A" << endl;
    for (itrA = A.begin(); itrA != A.end(); itrA++)
    {
        cout << *itrA << " ";
    }
    cout << endl;
    cout << endl;

    for (itrA = A.begin(); itrA != A.end(); itrA++)
    {
        if (*itrA > 0)
        {
            A.insert(itrA, 0);
            break;
        }
    }

    cout << "Deque A with semicolons" << endl;
    for (itrA = A.begin(); *itrA != A.back(); itrA++)
    {
        cout << *itrA << ";";
    }
    cout << *itrA << endl;
    return 0;
}