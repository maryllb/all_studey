#pragma once
#include "Programmer.h"
#include <iostream>
using namespace std;
class junior_programmer : public Programmer
{
public:
    junior_programmer(int salary);
    ~junior_programmer();
    void set_salary(int salary);                                                                                                             
    int get_salary();
    friend ostream& operator<<(ostream& os,junior_programmer &j);
};

