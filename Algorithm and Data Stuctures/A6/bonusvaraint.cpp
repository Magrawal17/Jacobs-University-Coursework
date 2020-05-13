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

int pushdown(int arr[], int size, int root)
{
    int index = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left >= size)
    {
        return root;
    }
    if (right >= size)
    {
        int temp = arr[left];
        arr[left] = arr[root];
        arr[root] = temp;
        return left;
    }
    if (arr[left] > arr[right])
    {
        index = left;
    }
    else
    {
        index = right;
    }
    int temp2 = arr[root];
    arr[root] = arr[index];
    arr[index] = temp2;
    return pushdown(arr, size, index);
}

void checkheap(int arr[], int size, int root)
{
    int parent = (root - 1) / 2;
    if (arr[parent] < arr[root])
    {
        int temp = arr[root];
        arr[root] = arr[parent];
        arr[parent] = temp;
        checkheap(arr, size, root);
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

void heapsortvaraint(int arr[], int size)
{
    buildmaxheap(arr, size);
    for (int i = size - 1; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        size = size - 1;
        int pos = pushdown(arr, size, 0);
        checkheap(arr, size, pos);
    }
}

int main()
{
    ofstream out;
    out.open("Data.txt");
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
        
        auto start1 = high_resolution_clock::now();
        heapsortvaraint(arr, size);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        out << size << " " << (double)duration.count()<< " " << (double)duration1.count() <<endl;
    }
}