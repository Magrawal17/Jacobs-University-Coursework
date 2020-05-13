/*
 CH-231-A
 a2_p5.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;

int main()
{
    set<int> Lotto;
    srand ( static_cast <unsigned int> (time(0)));
    srand (time(NULL) );
    int random;
    
    while (Lotto.size() <= 6)
    {
        random = rand() % 49 + 1;
        Lotto.insert(random);
    }

    set<int>::iterator pos;
  
    for (pos = Lotto.begin(); pos != Lotto.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;
    return 0;
}