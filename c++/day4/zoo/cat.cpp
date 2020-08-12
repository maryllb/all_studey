#include <iostream>
#include "cat.h"

using namespace std;
cat::cat()
{
    cout<<"cat::cat()"<<endl;
}
cat::~cat()
{
    cout<<"cat::~cat()"<<endl;
}

void cat::voice()
{
    cout<<"the cat miaomiao~"<<endl;
}
