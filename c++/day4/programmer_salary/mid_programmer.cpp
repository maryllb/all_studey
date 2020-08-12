#include <iostream>
#include "mid_programmer.h"
#include "Programmer.h"
using namespace std;

mid_programmer::mid_programmer(int salary):Programmer(salary)
{
    cout<<"mid_programmer::mid_programmer()"<<endl;
}
mid_programmer::~mid_programmer()
{
    cout<<"mid_programmer::~mid_programmer()"<<endl;
}
void mid_programmer::set_salary(int salary)
{
    if(salary <= 0) this->salary = 0;
    this->salary = salary;
}
int mid_programmer::get_salary()
{
    return this->salary;
}
ostream & operator<<(ostream &os,mid_programmer j)
{
    os<<"mid_programmer salary:"<<j.get_salary()<<endl;
    return os;
}
