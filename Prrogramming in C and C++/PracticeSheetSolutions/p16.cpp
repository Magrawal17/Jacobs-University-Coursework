
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
class Taxi : Car {
	protected:
		int limit;
	public:
		Taxi(std::string nBrand, std::string nModel, float nPrice, int nLimit) : Car(nBrand, nModel, nPrice) {
			limit = nLimit;
		}
		Taxi() : Car() {
			limit = 0;
		}
		~Taxi() {}
		void print() {
			std::cout << "Brand name is " << brand<<std::endl;
			std::cout << "Model name is " << model<<std::endl;
			std::cout << "Price is " << price<<std::endl;
			std::cout << "Passenger limit is " << limit<<std::endl;
		}

};

int main() {

	Taxi t("mercedes", "e", 10000.24, 10);
	t.print();

	return 0;
}