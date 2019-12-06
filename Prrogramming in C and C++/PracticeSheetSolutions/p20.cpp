#include <iostream>

class worker {
private:
	int id;
	std::string name;
public:
	worker(int id, std::string name) {
		this->id = id;
		this->name = name;
	} 
	friend std::ostream & operator << (std::ostream &out, const worker &w) {
    out << "id: " << w.id << std::endl<< "name: " << w.name << std::endl ;
    return out;
    }
};
int main() {
	worker a(234, "John McEnroe");
	worker b(324, "Jack Nicholson");
	std::cout << a << b;
	return 0;
}