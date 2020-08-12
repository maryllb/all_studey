#pragma once
#include "Programmer.h"
#include <iostream>
using namespace std;
class mid_programmer : public Programmer
{
public:
    mid_programmer(int salary);
    ~mid_programmer();
    void set_salary(int salary);                                                                                                             
    int get_salary();
    friend ostream & operator<<(ostream& os,mid_programmer j);
private:

};

