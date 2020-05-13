#include <iostream>
//#include "Binarytree.h"
using namespace std;

class Linkedlist
{
private:
    struct list
    {
        int data;
        list *ptr;
    };
    list *head;
public:
    Linkedlist()
    {
        this->head = NULL;
    }
    void push(int data)
    {
        struct list *newel = new list;
        newel->data = data;
        newel->ptr = head;
        head=newel;
    }
    void reverse()
    {
        struct list *prev = NULL;
        struct list *cursor = head;
        struct list *ahead = NULL;
        while (cursor != NULL)
        {
            ahead = cursor->ptr;
            cursor->ptr = prev;
            prev = cursor;
            cursor = ahead;
        }
        head = prev;
    }
    void print()
    {
        struct list *temp;
        for (temp = this->head; temp != NULL; temp = temp->ptr)
        {
            cout << temp->data << " ";
        }
        cout<<endl;
    }
};
