#include <iostream>

using namespace std;

template<class type>
void swapTemplate(type &a1,type &a2)
{
    type temp = a1;
    a1 = a2;
    a2 = temp;
}
int main()
{
    int i = 0,j = 4;
    cout<<"i"<<i<<" j"<<j<<endl;
    swapTemplate(i,j);
    cout<<"i"<<i<<" j"<<j<<endl;
    return 0;
}

