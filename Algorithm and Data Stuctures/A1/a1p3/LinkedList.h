/*
 CH-231-A
 a1_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
using namespace std;

template <class T>
class Item
{
public:
    T data;
    Item *prev;
    Item *next;
};

template <class T>
class Linkedlist
{
private:
    Item<T> *start;
    Item<T> *end;
    int counter;

public:
    Linkedlist()
    {
        start = NULL;
        end = NULL;
        counter = 0;
    }

    ~Linkedlist()
    {
        Item<T> *temp = this->start;
        Item<T> *temp1;
        for (int i = 0; i < counter; i++)
        {
            temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
    }

    T startitem()
    {
        return start->data;
    }

    T lastitem()
    {
        return end->data;
    }

    int getSize()
    {
        return this->counter;
    }

    void addstart(T newdata)
    {
        Item<T> *newelem = new Item<T>;
        newelem->data = newdata;
        newelem->prev = NULL;
        newelem->next = this->start;
        if ((this->counter) == 0)
        {
            this->start = newelem;
            this->end = newelem;
        }
        else
        {
            this->start->prev = newelem;
            this->start = newelem;
        }
        this->counter++;
    }

    void addend(T newdata)
    {
        Item<T> *newelem = new Item<T>;
        newelem->data = newdata;
        newelem->next = NULL;
        newelem->prev = this->end;
        if ((this->counter) == 0)
        {
            this->start = newelem;
            this->end = newelem;
        }
        else
        {
            this->end->next = newelem;
            this->end = newelem;
        }
        this->counter++;
    }

    T deletestart()
    {
        T data;
        if (counter == 0)
        {
            cout << "Not possbile to delete" << endl;
            return -1;
        }
        else
        {
            Item<T> *temp = this->start;
            this->start = temp->next;
            data = temp->data;
            delete temp;
            this->start->prev = NULL;
            this->counter--;
            return data;
        }
    }

    T deleteend()
    {
        T data;
        if (counter == 0)
        {
            cout << "Not possbile to delete" << endl;
            return -1;
        }
        else
        {
            Item<T> *temp = this->end;
            this->end = temp->prev;
            data = temp->data;
            delete temp;
            this->end->next = NULL;
            this->counter--;
            return data;
        }
    }
};
