#pragma once
#include <iostream>

using namespace std;
class myArray
{
public:
    myArray();
    myArray(int len);
    myArray(const myArray &another);
    ~myArray();
    void setData(int index,int data);
    int getData(int index);
    int getLen();
    void setIndex(int index);
    int getIndex();
    void operator=(const myArray &another);
    friend ostream &operator<<(ostream &os,const myArray &another);
    friend istream &operator>>(istream &is,myArray &anohter);
private:
    int len;
    int index;
    int* space;
};

