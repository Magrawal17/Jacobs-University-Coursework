
#include <iostream>
#include <string>

class Car {
	protected:
		std::string brand;
		std::string model;
		float price;
	public:
		Car() {
			brand = "default_brand;";
			model = "default_model";
			price = 0.0;
		}
		Car(std::string nBrand, std::string nModel, float nPrice) : brand(nBrand), model(nModel), price(nPrice) {}
		~Car() {}
		Car(const Car& c) {
			brand = c.brand;
			model = c.model;
			price = c.price;
		}
		void setBrand(std::string brand) {
			this->brand = brand;
		}
		void setModel(std::string model) { this->model = model; }
		void setPrice(float price) {
			this->price = price;
		}
		std::string getBrand() {
			return brand;
		}
		std::string getModel() {
			return model;
		}
		float getPrice() {
			return price;
		}
};