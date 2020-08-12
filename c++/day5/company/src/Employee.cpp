#include <iostream>
#include "../include/Employee.h"

using namespace std;
int Employee::startNum = 1000;

Employee::Employee()
{
    cout<<"Employee::Employee()"<<endl;
    level = 0;
    id = startNum++;
    salary = 0.0;
}
Employee:: ~Employee()
{
    cout<<"Employee::~Employee()"<<endl;
}
void Employee:: display()
{
    cout << "员工姓名" << this->name << endl;
    cout << "员工的级别" << this->level << endl;
    cout << "员工的月薪 " << this->salary << endl;
    cout << "员工的ID" << this->id << endl;
}

