#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class HashTable
{
private:
    Node **arr;
    int maxSize;
    int currentSize;

public:
    HashTable()
    {
        maxSize = 701;
        currentSize = 0;
        arr = new Node *[maxSize];
        for (int i = 0; i < 701; i++)
        {
            arr[i] = NULL;
        }
    }

    int hashCode(int key)
    {
        return key % maxSize;
    }

    void insertNode(int key, int value)
    {
        int j;
        int i = 0;
        do
        {
            j = hashCode(key + i);
            if (arr[j] == NULL)
            {
                arr[j] = new Node(key, value);
                this->currentSize++;
                
                return;
            }
            else
            {
                i++;
            }
        } while (i != maxSize);
        cout << "Overflow Occured" << endl;
    }

    int get(int key)
    {
        int j;
        int i = 0;
        do
        {
            j = hashCode(key + i);
            if (arr[j]->key == key)
            {
                return arr[j]->value;
            }
            else
            {
                i++;
            }
        } while ((i == maxSize) || arr[j] == NULL);

        return -1;
    }

    bool isEmpty()
    {
        if (this->currentSize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    HashTable hash; 

    for (int i = 0; i < 20; i++)
    {
        hash.insertNode(i*i/2, i);
    }
    
    for (int i = 0; i < 20; i++)
    {
         cout << hash.get(i*i/2) << " ";
    }
    cout<<endl;
    
    return 0;
}