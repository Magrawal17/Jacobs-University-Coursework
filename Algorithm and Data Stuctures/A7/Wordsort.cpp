#include <iostream>
#include <string>
using namespace std;

void Countsort(string arr[], int size, int pos)
{
    int range = 129;
    string temp[size];
    int count[range];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int j = 0; j < size; j++) {
        if (pos < arr[j].size()) {
            count[arr[j][pos] + 1] = count[arr[j][pos] + 1] + 1;
        }
        else {
            count[0] = count[0] + 1;
        }
    }

    for (int k = 1; k < range; k++) {
        count[k] = count[k] + count[k - 1];
    }

    for (int r = size - 1; r >= 0; r--) {
        if (pos < arr[r].size()) {
            temp[count[arr[r][pos] + 1] - 1] = arr[r];
            count[arr[r][pos] + 1] = count[arr[r][pos] + 1] - 1;
        }
        else {
            temp[count[0] - 1] = arr[r];
            count[0] = count[0] - 1;
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void Radixsort(string array[], int size)
{
    int max = array[0].size();
    for (int i = 1; i < size; i++) {
        if (array[i].size() > max) {
            max = array[i].size();
        }
    }
    for (int i = max - 1; i >= 0; i--) {
        Countsort(array, size, i);
    }
}

int main()
{
    string arr[] = { "word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time" };
    Radixsort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}

