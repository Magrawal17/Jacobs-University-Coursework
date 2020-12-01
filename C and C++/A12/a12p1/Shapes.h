/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();	
        ~Shape();				// empty shape
        std::string getName();
        void setName(std::string newname);
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  
};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
        ~CenteredShape();
		CenteredShape(const CenteredShape&);
		void move(double, double);	// moves the shape, i.e. it modifies it center
        void setX(double newx);
        void setY(double newy);
        double getX();
        double getY();
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	private: 
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
        ~RegularPolygon();
		RegularPolygon(const RegularPolygon&);
        void setEdgesNumber(int newedgesnumber);
        int getEdgesNumber();
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	private:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
        ~Circle();
		Circle(const Circle&);
        void setRadius(double newradius);
        double getRadius();
};

class Hexagon : public RegularPolygon {  // a Circle is a shape with a center and a radius
	private:
		double side;
        std::string color;
	public:
		Hexagon(const std::string&, double, double,double,const std::string&);
		Hexagon();
        ~Hexagon();
		Hexagon(const Hexagon&);
        void setside(double newsetside);
        double getside();
        void setcolor(std::string newcolor);
        std::string getColor();
        double area();
        double perimeter();
};
    
#endif