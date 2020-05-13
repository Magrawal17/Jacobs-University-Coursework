/*
 CH-231-A
 a2_p8.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include "Access.h"
using namespace std;


void Access::activate(unsigned int code,unsigned int level)
{
   this->code[code] = level;
};

void Access::deactivate(unsigned int code)
{
    this->code.erase(code);
};

bool Access::isactive(unsigned int code,unsigned int level) const
{
    if (this->code.find(code)->second >= level)
    {
        return true;
    }
    else
    {
        return false;
    }
};