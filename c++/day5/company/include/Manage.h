#pragma once
#include<string>
#include "../include/Manage.h"
#include "../include/Employee.h"
class Manage:public Employee
{
public:
    Manage();
    ~Manage();
    virtual void init(string name);
    virtual void uplevel(int level);
    //提成
    void getroyalty(double saleroom);
    virtual double getsalary();

private:

};

