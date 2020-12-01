#include <iostream>
using namespace std;
class Person {
protected:
string name;
int age;
public:
˜Person() {
cout << "Person destructor" << endl;
11
}
};
class Student : public virtual Person {
protected:
long int matr_nr;
public:
˜Student() {
cout << "Student destructor" << endl;
}
};
class Faculty : public virtual Person {
protected:
int employ_nr;
public:
˜Faculty() {
cout << "Faculty destructor" << endl;
}
};
class TA : public Student, public Faculty {
private:
string course_nr;
public:
TA() {
course_nr = "CH_230_A";
}
TA(const TA &obj) {
this->name = obj.name;
this->age = obj.age;
this->matr_nr = obj.matr_nr;
this->employ_nr = obj.employ_nr;
this -> course_nr = obj.course_nr;
}
˜TA() {
cout << "TA destructor" << endl;
}
friend void print(const TA a);
};
void print(const TA a) {
cout << a.course_nr << endl;
}
int main() {
TA ta1;
TA ta2(ta1);
print(ta2);
return 0;
}