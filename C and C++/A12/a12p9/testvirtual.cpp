#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"
 
const int num_obj = 25;
int main() {
	Area *list[num_obj];						// An array of Area with 6 elements is created
	int index = 0;								// Index Initialized
	double sum_area = 0.0;						// Sum_area Initialized
	double sum_perimeter = 0.0;
	
	const char* colors[4]={"RED","BLACK","VIOLET","BLUE"};
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber;
	int colorindex;
	int sizea;
	int sizeb;
	int choice;
	
	for (int i = 0; i < 25; i++)
	{
		randomNumber = rand();
		colorindex=randomNumber%4;
		randomNumber = rand();
		sizea=(randomNumber%95)+5;
		randomNumber = rand();
		sizeb=(randomNumber%95)+5;
		randomNumber = rand();
		choice=randomNumber%4;
		switch (choice)
		{
		case 0:
			list[i]=new Circle (colors[colorindex],sizea);
			break;
		case 1:
			list[i]=new Ring (colors[colorindex],sizea,sizeb);
			break;
		case 2:
			list[i]=new Rectangle(colors[colorindex],sizea,sizeb);
			break;
		case 3:
			list[i]=new Square(colors[colorindex],sizeb);
			break;
		}
	}
	
	
	
	
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


