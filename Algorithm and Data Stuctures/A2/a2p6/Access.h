/*
 CH-231-A
 a2_p6.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <set>
using namespace std;

class Access
{
public:
    void activate(unsigned int code);
    void deactivate(unsigned int code);
    bool isactive(unsigned int code) const;
private:
    set<unsigned int> code;
};