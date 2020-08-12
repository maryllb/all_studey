#include <iostream>
#include "Data.h"
using namespace std;
int main()
{
    Data d1(31,7,2020);
    Data d2 = d1;
    Data d3(07,11);
    Data d4;
    cout<<d1;
    cout<<d2;
    cout<<d3;
    cout<<d4;
    return 0;
}

