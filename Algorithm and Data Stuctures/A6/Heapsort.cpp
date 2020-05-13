#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void maxheapify(int arr[], int size, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest;
    if (left < size && arr[left] > arr[root])
    {
        largest = left;
    }
    else
    {
        largest = root;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        maxheapify(arr, size, largest);
    }
}

void buildmaxheap(int arr[], int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        maxheapify(arr, size, i);
    }
}

void heapsort(int arr[], int size)
{
    buildmaxheap(arr, size);
    for (int i = size - 1; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        size = size - 1;
        maxheapify(arr, size, 0);
    }
}

int main()
{
    ofstream out;
    out.open("DataNormal.txt");
    for (int size = 0; size < 100000; size = size + 1000)
    {
        int arr[size];
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % size;
        }
        auto start = high_resolution_clock::now();
        heapsort(arr, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        out << size << " " << (double)duration.count() << endl;
    }
}