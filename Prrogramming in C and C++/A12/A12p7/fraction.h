/*
 CH-230-A
 a12_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
								// integers. Denominator by default is 1
	friend std::ostream& operator <<(std::ostream& out ,const Fraction &obj);
	friend std::istream& operator >>(std::istream& in ,Fraction &obj);	
	Fraction operator *(Fraction& obj);
	Fraction operator /(Fraction& obj);
	Fraction operator +(Fraction& obj);		
	Fraction operator -(Fraction& obj);	
	Fraction& operator =(const Fraction&obj);
	bool operator <(const Fraction &obj);
	bool operator >(const Fraction &obj);		
};


#endif /* FRACTION_H_ */