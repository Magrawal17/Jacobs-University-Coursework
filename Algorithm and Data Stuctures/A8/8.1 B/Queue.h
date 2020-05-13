#include "Stack.h"

template <class T>
class Queue
{
private:
    Stack<T> Stack1;
    Stack<T> Stack2;
    int size;
public:
    Queue()
    {
        size=0;
    }
    void Enqueue(T data)
    {
        Stack1.push(data);
        this->size++;
    }
    T Dequeue()
    {
        if(Stack2.isEmpty()==true)
        {
            while (!Stack1.isEmpty())
            {
                T temp=Stack1.pop();
                Stack2.push(temp);
            }
        }
        this->size--;
        return Stack2.pop();
    }
    bool isEmpty()
    {
        if (this->size==0)
        {
            return true;
        }
        else
        {
            return false;
        }    
    }
};

