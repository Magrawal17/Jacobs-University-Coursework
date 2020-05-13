/*
 CH-231-A
 a2_p1.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    list<int> A;
    list<int> B;

    int input;
    cin >> input;
    while (input > 0)
    {
        A.push_back(input);
        B.push_front(input);
        cin >> input;
    }
    cout << endl;
    cout<<"List A"<<endl;
    list<int>::iterator itrA;
    for (itrA = A.begin(); itrA != A.end(); itrA++)
    {
        cout << *itrA << " ";
    }
    cout << endl;

    ofstream out;
    out.open("listB.txt", ios::out);
    out<<"List B"<<endl;
    list<int>::iterator itrB;
    for (itrB = B.begin(); itrB != B.end(); itrB++)
    {
        out << *itrB << " ";
    }

    cout << endl;
    
    int temp;
    temp = A.front();
    A.pop_front();
    A.push_back(temp);

    B.splice(B.end(),B,B.begin());

    cout<<"List A with comma"<<endl;
    for (itrA = A.begin(); *itrA != A.back(); itrA++)
    {
        cout << *itrA <<",";
    }
    cout<<*itrA<<endl;
    
    cout<<"List B with comma"<<endl;
    for (itrB = B.begin(); *itrB != B.back(); itrB++)
    {
       cout << *itrB <<",";
    }
    cout<<*itrB<<endl;
     cout << endl;


    A.merge(B);
    A.sort();
    cout<<"List A sorted with B"<<endl;
    for (itrA = A.begin(); itrA != A.end(); itrA++)
    {
        cout << *itrA << " ";
    }
    cout << endl;
    return 0;
}
