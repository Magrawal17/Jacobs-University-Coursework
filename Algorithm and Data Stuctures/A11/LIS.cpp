#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printLIS(vector<int> a, int n)
{
    vector<vector<int>> arr(n);

    arr[0].push_back(a[0]); //first element will have LIS one already

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((a[i] > a[j]) && (arr[j].size() + 1 > arr[i].size()))
            {
                arr[i] = arr[j]; // find the max(arr[j])
            }
        }
        arr[i].push_back(a[i]); //push the current elemnt in the second vector
    }

    vector<int> max; //finding max vecotr
    for (vector<int> i : arr)
    {
        if (i.size() > max.size())
        {
            max = i;
        }
    }
    
    for (int i : max)
    { 
        cout << i << " ";   //printing that vector
    }
    cout << endl;
}

int main()
{
    ifstream input;
    input.open("input1.txt");
    vector<int> arr;
    int temp;
    while (!input.eof())
    {
        input >> temp;
        arr.push_back(temp);
    }
    input.close();
    printLIS(arr, arr.size());
    return 0;
}