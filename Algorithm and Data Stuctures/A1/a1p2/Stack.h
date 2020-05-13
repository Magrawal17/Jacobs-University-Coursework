/*
 CH-231-A
 a1_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    int size;
    int index;
    T *arr;

public:

    Stack()
    {
        size = 10;
        arr = new T[size];
        index = 0;
    };

    Stack(const Stack &obj)
    {
        this->size = obj.size;
        this->arr = new T[obj.size];
        for (int i = 0; i < (this->size); i++)
        {
            this->arr[i] = obj.arr[i];
        }
        this->index = obj.index;
    };

    Stack(int size)
    {
        this->size = size;
        this->arr = new T[size];
        this->index = 0;
    };

    bool push(T element);

    bool pop(T &out)
    {
        if (this->index == 0)
        {
            cout << "Stack is Empty" << endl;
            return false;
        }
        this->index=this->index-1;
        out = this->arr[this->index]; //unsure need to check this
        return true;
    }
    
    T back(void)
    {
        return this->arr[(this->index) - 1];
    };

    int getNumEntries()
    {
        return index;
    };
    
    ~Stack()
    {
        delete[] this->arr;
    }
     
    void print()        //self reference
    {
        for (int i = 0; i < index; i++)
        {
            cout<<this->arr[i]<<"  ";
        }
        cout<<endl;
    }
};
template <class T>
bool Stack<T>::push(T element)
    {
        if (this->index == this->size)
        {
           cout<<"Stack is full"<<endl;
           return false;
        }
        this->arr[this->index] = element;
        this->index=this->index + 1;
        return true;
    }
