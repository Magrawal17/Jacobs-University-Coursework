#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketsort(float arr[], int size)     
{
    vector<float> bucket[size];
    for (int i = 0; i < size; i++) {
        bucket[int(size * arr[i])].push_back(arr[i]); //puting elements into different buckets
    }

    for (int i = 0; i < size; i++) {
        sort(bucket[i].begin(), bucket[i].end()); //sort the individual buckets
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j]; //concatinating all the buckets
        }
    }
}

int main()
{
    float arr[] = { 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1 };
    bucketsort(arr, 7);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}