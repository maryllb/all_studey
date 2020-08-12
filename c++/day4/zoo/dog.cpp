#include <iostream>
#include "dog.h"

using namespace std;
dog::dog()
{
    cout<<"dog::dog()"<<endl;
}
dog::~dog()
{
    cout<<"dog::~dog()"<<endl;
}

void dog::voice()
{
    cout<<"the dog wangwang~"<<endl;
}
