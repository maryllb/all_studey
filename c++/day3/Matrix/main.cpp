#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix m1;
    int a1[3][3];
    int a2[3][3];
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            a1[i][j] = 1; 
            a2[i][j] = 2;
        }
    }
    
    cout<<"m1:"<<endl;
    cout<<m1;
    Matrix m2(a1);
    cout<<"m2:"<<endl;
    cout<<m2;
    Matrix m3(a2);
    cout<<"m3:"<<endl;
    cout<<m3;
    Matrix m4 = m2+m3;
    cout<<"m4 = m2+m3:"<<endl;
    cout<<m4;
    Matrix m5 = m2 * m3;
    cout<<"m5 = m2 *m3:"<<endl;
    cout<<m5;
    m2 += m3;
    cout<<"m2 += m3:"<<endl;
    cout<<m2;
    m2 *= m3;
    cout<<"m2 *= m3:"<<endl;
    cout<<m2;


    return 0;
}

