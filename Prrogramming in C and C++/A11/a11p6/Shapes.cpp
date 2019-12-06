// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"
using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << "Name: " << name << endl;
}

Shape::Shape() 
{
    name="Default Shape";
}

void Shape::setName(std::string newname)
{
    name =newname;
}

string Shape::getName()
{
    return name;
}
//
CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

CenteredShape::CenteredShape() : Shape()
{
    x=0;
    y=0;
}

void CenteredShape::setX(double newx)
{
    x=newx;
}

void CenteredShape::setY(double newy)
{
    y=newy;
}

double CenteredShape::getX()
{
    return x;
}

double CenteredShape::getY()
{
    return y;
}
//
RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) : CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

RegularPolygon::RegularPolygon() : CenteredShape()
{
        EdgesNumber=0;
}

void RegularPolygon::setEdgesNumber(int newedgesnumber)
{
    EdgesNumber=newedgesnumber;
}

int RegularPolygon::getEdgesNumber()
{
    return EdgesNumber;
}
//
Circle::Circle(const string& n, double nx, double ny, double r) : CenteredShape(n,nx,ny) 
{
	Radius = r;
}

void Circle::setRadius(double newradius){
	Radius=newradius;
}

double Circle::getRadius(){
    return Radius;
}

double Circle::area()
{
    return 3.14*Radius*Radius;
}

double Circle::perimeter()
{
    return 2*3.14*Radius;
}
Rectangle::Rectangle() : RegularPolygon()
{
    width=0;
    height=0;
}

Rectangle::Rectangle(const string& n,double nx,double ny,double nwidth,double nheight) : RegularPolygon(n,nx,ny,4)
{
        width=nwidth;
        height=nheight;
}

void Rectangle::setWidth(double newwidth)
{
    width=newwidth;
}

void Rectangle::setheight(double newheight)
{
	height=newheight;
}


double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::area()
{
    return width*height;
}

double Rectangle::perimeter()
{
    return (2*(width+height));
}

Square::Square():Rectangle()
{
    side=0;
}

Square::Square(const string& n,double nx,double ny,double nside) : Rectangle(n,nx,ny,nside,nside)
{
    side=nside;
}

void Square::setside(double newside)
{
	side=newside;
}

double Square::getside()
{
	return side;
}