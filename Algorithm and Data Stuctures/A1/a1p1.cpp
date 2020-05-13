/*
 CH-231-A
 a1_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <iostream>
using namespace std;

//template <typename T>
//struct identity { typedef T type; }; typename identity<T>::type

class Complex
{
private:
    double re, im;

public:
    Complex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }

    bool operator==(const Complex &o)
    {
        if ((this->re == o.re) && (this->im == o.im))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Complex operator+(const Complex o)
    {
        return Complex(this->re + o.re, this->im + o.im);
    }
    friend ostream &operator<<(ostream &o, Complex c)
    {
        o << c.re << "+" << c.im << "i" << endl;
        return o;
    }
};

template <typename T>
int array_search(T arr[], int size, T search)
{
    for (int i = 0; i < size; i++)
    {
        if (search == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int intarr[] = {1, 2, 3, 4, 5, 6};
    cout << array_search(intarr, 6, 5) << endl;

    double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << array_search(darr, 6, 3.8) << endl;

    string sarr[] = {"apple", "cherry", "orange"};
    cout << array_search(sarr, 3, string("apple")) << endl;

    Complex carr[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
    cout << array_search(carr, 3, Complex(-3, -5)) << endl;
}