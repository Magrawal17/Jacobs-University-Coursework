#include <iostream>


int main() {
	
	int x;  //numerator
	int y;	//denominator

	std::cin >> x;
	std::cin >> y; 

	try {
		if (y == 0) {
			throw std::logic_error("Division by zero.");
		}
		std::cout << x/y << std::endl; 
	}
	
	catch (std::logic_error& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
} 


