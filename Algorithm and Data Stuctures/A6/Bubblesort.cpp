#include <iostream>
using namespace std;

void Bubblesort(int arr[],int size)
{
    int temp;
    bool swap= false;
    for (int i = 0; i < size-1; i++)    //going through entire loop
    {
        for (int j = 0; j < size-1-i; j++)      //checking each elemetn with  all other elemetns till I
        {                                        //as elemts till i will have already sorted
            swap = false;                                    
            if (arr[j]>arr[j+1])    //swapping element
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;      //optimizing it so that it doesnt run once it sorted
            }
        } 
        if (swap==false)
        {
            break;
        }
    }
    
}

int main()
{
    int size=1000;
    int arr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)  //randomizing elements
    {
        arr[i]=rand() % size;
    }
    Bubblesort(arr,size);
    for (int i = 0; i < size; i++)      //printing elemetnts
    {
        cout<<arr[i]<<endl;
    }
}