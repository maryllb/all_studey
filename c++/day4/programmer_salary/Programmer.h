#pragma once
#include <iostream>
using namespace std;
class Programmer
{
public:
    Programmer(int salary);
    virtual ~Programmer();
    virtual void set_salary(int salary) = 0;
    virtual int get_salary() = 0;
protected:
    int salary;

};

