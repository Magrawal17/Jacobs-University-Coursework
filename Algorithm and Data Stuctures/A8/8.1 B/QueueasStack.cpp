#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> temp;
    for (int i = 0; i < 10; i++)
    {
        temp.Enqueue(i);
    }
    while (!temp.isEmpty())
    {
       cout << temp.Dequeue() << " ";
    }
    cout<<endl;
}