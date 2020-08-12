#include <iostream>
#include "Programmer.h"
using namespace std;
Programmer::Programmer(int salary)
{
    this->salary = salary;
    cout <<"Programmer::Programmer()"<<endl;
}
Programmer::~Programmer()
{
    cout <<"Programmer::~Programmer()"<<endl;
}
