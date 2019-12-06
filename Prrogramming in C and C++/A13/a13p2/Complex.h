/*
CH-230-A
a10_p9.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/


using namespace std;

class Complex
{
private:
  		int real;
  		int imag;

public:
  		Complex();
  		Complex(float, float);
  		Complex(Complex &obj);
 		~Complex();
  
  		void setreal(float);
  		void setimag(float);

	  	float getreal();
  		float getimag();

	  	Complex operator + (Complex &);
  		Complex operator - (Complex &);
  		Complex operator * (Complex &);
  		Complex operator = (const Complex &);

 	 	friend ostream &operator <<(ostream &, const Complex &);
  		friend istream &operator >>(istream &, Complex &);
};