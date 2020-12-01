#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;

public:
    Person()
    {
        cout << "Person constuctor" << endl;
    }
    ~Person()
    {
        cout << "Person destructor" << endl;
    }
};
class Student : public virtual Person
{
protected:
    long int matr_nr;

public:
    Student()
    {
        cout << "Student constructor" << endl;
    }
    ~Student()
    {
        cout << "Student destructor" << endl;
    }
};
class Faculty : public virtual Person
{
protected:
    int employ_nr;

public:
Faculty(){
    cout << "Faculty constructor" << endl;
}
    ~Faculty()
    {
        cout << "Faculty destructor" << endl;
    }
};
class TA : public Student, public Faculty
{
private:
    string course_nr;

public:
    TA()
    {
        course_nr = "CH_230_A";
        cout << "TA constructor" << endl;
    }
    TA(const TA &obj)
    {
        this->name = obj.name;
        this->age = obj.age;
        this->matr_nr = obj.matr_nr;
        this->employ_nr = obj.employ_nr;
        this->course_nr = obj.course_nr;
    }
    ~TA()
    {
        cout << "TA destructor" << endl;
    }
    friend void print(const TA a);
};
void print(const TA a)
{
    cout << a.course_nr << endl;
}
int main()
{
    TA ta1;
    //TA ta2(ta1);
    print(ta1);
    return 0;
}