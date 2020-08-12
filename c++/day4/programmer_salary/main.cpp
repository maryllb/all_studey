#include <iostream>
#include "Programmer.h"
#include "adv_programmer.h"
#include "mid_programmer.h"
#include "junior_programmer.h"
using namespace std;
int main()
{
    Programmer *p1 = new junior_programmer(5000);
    Programmer *p2 = new mid_programmer(12000);
    Programmer *p3 = new adv_programmer(20000);
    cout<<p1->get_salary()<<endl;
    cout<<p2->get_salary()<<endl;
    cout<<p3->get_salary()<<endl;
    cout<<p1;
    cout<<p2;
    cout<<p3;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}

