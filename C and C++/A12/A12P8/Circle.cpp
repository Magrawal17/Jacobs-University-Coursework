#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(const char *n, double a) : Area(n) {
	radius = a;
}

Circle::~Circle() {
}

double Circle::calcArea() const {
	std::cout << "calcArea of Circle...";
	return radius * radius * M_PI;
}

double Circle::calcPerimeter() const{
	std::cout<<"calcPerimeter of Cirle...";
	return 2*M_PI*radius;
}
