#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
 
const int num_obj = 6;
int main() {
	Area *list[num_obj];						// An array of Area with 6 elements is created
	int index = 0;								// Index Initialized
	double sum_area = 0.0;						// Sum_area Initialized
	double sum_perimeter = 0.0;
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// Instance of Ring is being created.
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	list[0] = &blue_ring;						// First elements points out to blue ring
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	while (index < num_obj) {					// while condition for the loop to sun 6 times
		(list[index])->getColor();				
		double area = list[index]->calcArea();// calculating the area of the shape
		double perimeter=list[index]->calcPerimeter();
		sum_area += area;
		sum_perimeter += perimeter; 
		index++;
	}
	cout << "\nThe total area is "
			<< sum_area << " units " << endl;	// printing the total area
	cout << "\nThe total peimeter is "
			<< sum_perimeter << " units " << endl;
	return 0;
}
