#include <iostream>

class Complex {

	private:
		float real;
		float imag;

	public:
		Complex();
		Complex(float a, float b= 0) : real(a), imag(b) {};
		double magnitude() const;
		friend std::ostream& operator<<(std::ostream &out, const Complex &c);

		//you can declare them as friend instead 
		bool operator<(const Complex& c) const;
		bool operator>(const Complex& c) const;
};


double Complex::magnitude() const {
	return 0; //you dont need to complete this
}

std::ostream& operator<<(std::ostream &out, const Complex &c)
{
	if (c.imag)
		std::cout << std::noshowpos << c.real << std::showpos << c.imag << "i" <<std::endl;
	else
		std::cout << std::noshowpos << c.real << std::endl;
	return out;
}

bool Complex::operator<(const Complex& c) const {
	return magnitude() < c.magnitude();
}

bool Complex::operator>(const Complex& c) const{
	return magnitude() > c.magnitude();
}

int main() {

	Complex a(1, 2);
	std::cout << a;
	return 0;

}
