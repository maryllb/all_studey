#include <iostream>
#include "adv_programmer.h"
#include "Programmer.h"
using namespace std;

adv_programmer::adv_programmer(int salary):Programmer(salary)
{
    cout<<"adv_programmer::adv_programmer()"<<endl;
}
adv_programmer::~adv_programmer()
{
    cout<<"adv_programmer::~adv_programmer()"<<endl;
}
void adv_programmer::set_salary(int salary)
{
    if(salary <= 0) this->salary = 0;
    this->salary = salary;
}
int adv_programmer::get_salary()
{
    return this->salary;
}
ostream & operator<<(ostream &os,adv_programmer j)
{
    os<<"adv_programmer salary:"<<j.get_salary()<<endl;
    return os;
}
