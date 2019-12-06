/*
CH-230-A
a13_p8.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <exception>
using namespace std;


class OwnMaption : public exception
{
public:
    const char* what() const throw() { return  "OwnException\n"; }
};

void Excpetions(int a)
{
    if (a==1)
    {
        throw 'a';
    }
    else if(a== 2)
    {
        throw 12;
    }
    else if (a== 3)
    {
        throw true;
    }
    else if (a==4)
    {
        throw OwnMaption();
    }
}

int main()
{
    try { Excpetions(1);}
    catch (char text)
    {
        cerr << "Caught in main: " << text << endl;
    }
    try { Excpetions(2);}
    catch (int num)
    {
        cerr << "Caught in main: " << num << endl;
    } 
    try { Excpetions(3);}
    catch (bool ans)
    {
        cerr << "Caught in main: " << ans << endl;
    } 
    try { Excpetions(4);}
    catch (OwnMaption& temp)
    {
       cerr << "Caught in main: " << temp.what();
    }
    catch (...)
    {
        cerr << "Default case exception"<<endl;
    }
    return 0;
}
;