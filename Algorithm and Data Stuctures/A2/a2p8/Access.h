/*
 CH-231-A
 a2_p8.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <map>
using namespace std;

class Access
{
public:
    void activate(unsigned int code, unsigned int level);
    void deactivate(unsigned int code);
    bool isactive(unsigned int code, unsigned int level) const;
private:
    map<unsigned int,unsigned int> code;
};