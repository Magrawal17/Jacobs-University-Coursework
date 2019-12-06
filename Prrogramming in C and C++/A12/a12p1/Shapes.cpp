// please refer to shapes.h for methods documentation

#include <iostream>
#include <cmath>
#include "Shapes.h"

using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}
void Shape::setName(std::string newname)
{
    name =newname;
}

string Shape::getName()
{
    return name;
}

Shape::Shape()
{
    name="";
}



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

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

void RegularPolygon::setEdgesNumber(int newedgesnumber)
{
    EdgesNumber=newedgesnumber;
}

int RegularPolygon::getEdgesNumber()
{
    return EdgesNumber;
}

RegularPolygon::RegularPolygon() : CenteredShape()
{
        EdgesNumber=0;
}
Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

void Circle::setRadius(double newradius){
	Radius=newradius;
}

double Circle::getRadius(){
    return Radius;
}

Circle::Circle() : CenteredShape()
{
        Radius=0;
}

Hexagon::Hexagon(const std::string& n, double nx, double ny,double newside,const std::string& newcolor)
:RegularPolygon(n,nx,ny,6)
{
    side=newside;
    color=newcolor;
}

double Hexagon::area()
{
    return (3*sqrt(3)/2)*side*side;
}

double Hexagon::perimeter()
{
    return 6*side;
}

Shape::Shape(const Shape&obj)
{
    name=obj.name;
}

CenteredShape::CenteredShape(const CenteredShape&obj):Shape(obj)
{
    x=obj.x;
    y=obj.y;
}

RegularPolygon::RegularPolygon(const RegularPolygon&obj):CenteredShape(obj)
{
    EdgesNumber=obj.EdgesNumber;
}

Hexagon::Hexagon(const Hexagon&obj):RegularPolygon(obj)
{
    edges
    color=obj.color;
    side=obj.side;
}

Hexagon::~Hexagon()
{
    cout<<"Hexagon destroyed"<<endl;
}

Shape::~Shape()
{}

CenteredShape::~CenteredShape()
{}

RegularPolygon::~RegularPolygon()
{}

Circle::~Circle()
{}