/*
CH-230-A
a10_p3.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <string>


class City
{
    private:
    std::string name;
    int inhab;
    std::string mayor;
    double area;

    public:
    void setname(std::string newname);
    void setinhab(int newinhab);
    void setmayor(std::string newmayor);
    void setarea(double newarea);

    std::string getname();
    int getinhab();
    std::string getmayor();
    double getarea();

    void print();

};