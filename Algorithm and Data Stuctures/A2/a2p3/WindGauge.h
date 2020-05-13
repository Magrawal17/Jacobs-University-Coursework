/*
 CH-231-A
 a2_p3.cpp
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <deque>
using namespace std;

class WindGauge
{
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump();
private:
    int period;
    deque<int> WG;
};