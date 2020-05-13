/*
 CH-231-A
 a1_p5.c
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
        getline(cin, data);
        if (data == "END")
        {
            temp = false;
        }
        else
        {
            input.push_back(data);
        }
    }
    if (input.size() >= 5)
    {
        string temp = input[1];
        input[1] = input[4];
        input[4] = temp;
    }
    else
    {
        cout << "Error Swapping" << endl;
    }
    input.back()="???";
    int i;
    for (i = 0; i < (input.size()-1); i++)
    {
        cout << input[i] << ",";
    }
    cout << input[i] << endl;
    vector<string>::iterator iterinput = input.begin();
    for (int i = 0; i < (input.size() - 1); i++)
    {
        cout << *iterinput << ";";
        iterinput++;
    }
    cout << *iterinput << endl;
    for (iterinput = input.end() -1; iterinput >= input.begin(); iterinput--)
    {
        cout << *iterinput << " ";
    }
    cout<<endl;
}