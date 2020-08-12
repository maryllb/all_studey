#pragma once
#include "Programmer.h"
#include <iostream>
using namespace std;
class adv_programmer : public Programmer
{
public:
    adv_programmer(int salary);
    ~adv_programmer();
    void set_salary(int salary);                                                                                                             
    int get_salary();
    friend ostream & operator<<(ostream& os,adv_programmer j);
private:

};

