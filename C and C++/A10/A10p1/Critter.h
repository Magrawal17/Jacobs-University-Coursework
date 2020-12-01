/*
CH-230-A
a10_p1.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;
    double weight;
    std::string color;


public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
    void setWeight(double newweight);
    void setColor(std::string& newcolor);

	// getter method
	int getHunger();
    float getWeight();
    float getColor();
	// service method
	void print();
};