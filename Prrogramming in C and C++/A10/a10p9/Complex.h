/*
CH-230-A
a10_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

class Complex {

private: 
	float real;  
	float imag;  

public:
	Complex();                 
	Complex(float newreal,float newimag);  

	~Complex();
	Complex(Complex &b);
	void setreal(float newreal);
	void setimag(float newimag);
	
	float getimag();
	float getreal();

	void print();

	Complex conjugate();
	Complex add(Complex b);
	Complex sub(Complex b);
	Complex mult(Complex b);
};

