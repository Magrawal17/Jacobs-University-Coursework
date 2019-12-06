#include <iostream>
using namespace std;

class Creature {
	public:
		Creature();  
		void run() const;

	protected:
		int distance;
};

class Wizard : public Creature {
	public:
		Wizard();
		void hover() const;

	private:
		int distFactor;
};

class Dog : public Creature {
	public:
		Dog();
		void printing() const;

	private:
		string name;
};

class Cat : public Creature {
	public:
		Cat();
		void ran() const;

	private:
		int time;
};