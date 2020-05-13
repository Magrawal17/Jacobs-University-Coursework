/*
 CH-231-A
 a1_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> input;
    bool temp;
    string data;
    temp = true;
    while (temp == true)
    {
        cin >> data;
        if (data == "END")
        {
            temp = false;
        }
        else
        {
            input.push_back(data);
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    vector<string>::iterator iterinput = input.begin();
    for (int i = 0; i < (input.size() - 1); i++)
    {
        cout << *iterinput << ",";
        iterinput++;
    }
    cout << *iterinput << endl;
}