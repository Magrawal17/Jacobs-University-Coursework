#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> temp(5);
    for (int i = 0; i < 5; i++)
    {
        temp.push(i);
    }
    //temp.push(3); //this will bring excepition
    while (!temp.isEmpty())
    {
        cout << temp.pop() << endl;
    }
   // cout << temp.pop() << endl; //another exception
}