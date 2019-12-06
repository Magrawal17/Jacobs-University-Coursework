#include <iostream>

using namespace std;

class Creature {
	public:
		Creature();  
		void run() const;

	protected:
		int distance;
};

Creature::Creature(): distance(10)
{

}    

void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  

class Wizard : public Creature {
	public:
		Wizard();
		void hover() const;

	private:
		int distFactor;
};

Wizard::Wizard() : distFactor(3)
{}  

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

class Dog : public Creature {
	public:
		Dog();
		void printing() const;

	private:
		string name;
};

Dog::Dog()
{
    name="Joe";
}  

void Dog::printing() const
{
   cout<<"name:"<<name<<endl;
   cout<<"distance:"<<name<<endl;
}
class Cat : public Creature {
	public:
		Cat();
		void ran() const;

	private:
		int time;
};

Cat::Cat()
{
    time=14;
}  

void Cat::ran() const
{
   cout<<"time:"<<time<<endl;
   cout<<"distance:"<<distance<<endl;
}

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    cout << "\nCreating a Dog.\n";
   Dog d;
    d.run();
    d.printing();

    cout << "\nCreating a Cat.\n";
    Cat c1;
    c1.run();
    c1.ran();


    return 0;
} 