#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Object3D{
protected:
	string name;
public:
	Object3D(string name){
		this->name = name;
	}
	virtual float volume() const = 0;
	virtual ~Object3D(){};
};

class Sphere : public Object3D{
protected:
	float radius;
public:
	Sphere(string name, float radius) : Object3D(name){
		// not needed to complete the task on the exam

		this->radius = radius;
	}
	float volume() const{
		return (4/3)*M_PI*radius*radius*radius;
	}
};

class Cylinder : public Object3D{
protected:
	float radius;
	float height;
public:
	Cylinder(string name, float radius, float height) : Object3D(name){ 
		// not needed to complete the task on the exam
		this->radius = radius;
		this->height = height; 
	}
	float volume() const{
		return M_PI*radius*radius*height;
	}

};

class RectPrism : public Object3D{
protected:
	float width;
	float length;
	float height;
public:
	RectPrism(string name, float width, float length, float height) : Object3D(name){
		this->width = width;
		this->length = length;
		this->height = height;
	}
	float volume() const{
		return width*length*height;
	}

};

class Cube : public RectPrism{
protected:
	float side;
public:
	Cube(string name, float side) : RectPrism(name, side, side, side){
	}
	float volume() const{
		return side*side*side;
	}

};


int main(int argc, char *argv[]) {
	Object3D *arr[5];
	arr[0] = new Sphere("sphere", 1.3);
	arr[1] = new RectPrism("rectprism", 2.0, 3.0, 4.0);
	arr[2] = new Cylinder("cylinder", 2.0, 1.3);
	arr[3] = new Cube("cube", 2.0);
	arr[4] = new RectPrism("rectprism2", 1.0, 2.0, 3.5);
	int i;
	for(i=0; i<5; i++)
		cout << arr[i]->volume() << endl;
	for(i=0; i<5; i++)
		delete arr[i];
	return 0;
}