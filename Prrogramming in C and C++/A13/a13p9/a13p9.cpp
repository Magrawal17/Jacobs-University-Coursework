/*
CH-230-A
a13_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <exception>
using namespace std;

class Car;
class Garage;

class Motor
{
    public:
        Motor() { throw "This motor has problems"; }
};

class Car : public Motor
{
    public:
        Car() : Motor() {}
};

class Garage
{   
    public:
        Garage()
        {
            try
            {
                Car test1;
            }
            catch (const char *temp1)
            {
                cerr << "Caught in Garage: " << temp1 << endl;
            }
         throw "The car in this garage has problems with the motor";
        }
};

int main()
{
    try
    {
        Garage test2;
    }
    catch (const char *temp2)
    {
        cerr << "Caught in Main: " << temp2 << endl;
    }
    return 0;
} 