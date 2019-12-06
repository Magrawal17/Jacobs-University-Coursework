#include <iostream>
using namespace std;
#include "Creature.h"

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