/*
 CH-231-A
 a2_p6.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include "Access.h"
using namespace std;


void Access::activate(unsigned int code)
{
    this->code.insert(code);
};

void Access::deactivate(unsigned int code)
{
    this->code.erase(code);
};

bool Access::isactive(unsigned int code) const
{
    return this->code.find(code) != this->code.end();
};