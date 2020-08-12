#include <iostream>
#include "junior_programmer.h"
#include "Programmer.h"
using namespace std;

junior_programmer::junior_programmer(int salary):Programmer(salary)
{
    cout<<"junior_programmer::junior_programmer()"<<endl;
}
junior_programmer::~junior_programmer()
{
    cout<<"junior_programmer::~junior_programmer()"<<endl;
}
void junior_programmer::set_salary(int salary)
{
    if(salary <= 0) this->salary = 0;
    this->salary = salary;
}
int junior_programmer::get_salary()
{
    return this->salary;
}
ostream & operator<<(ostream &os,junior_programmer &j)
{    
    os<<"junior_programmer salary:";
    os<<j.get_salary()<<endl;
    return os;
}
