#include <iostream>
#include "../include/Manage.h"
#include "../include/Employee.h"
using namespace std;

Manage::Manage():Employee()
{
    this->level = 4;
    this->salary = 8000;
}
Manage::~Manage()
{
    cout<<"Manage::~Manage"<<endl;
}
void Manage::init(string name)
{
    this->name = name;
}
void Manage::uplevel(int level)
{
    if(this->level < 4) this->level++;
}
//提成
void getroyalty(double saleroom)
{

}
double getsalary();

