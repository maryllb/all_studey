#include <iostream>
#include "myArray.h"
using namespace std;

myArray::myArray()
{
    this->len = 0;
    this->space = NULL;
}
myArray::myArray(int len)
{
    if(len <= 0){
        this->len = 0;
        return;
    }
    this->len = len;
    this->space = new int[this->len];
    cout<<"myArray::myArray(int len)"<<endl;
}

myArray::myArray(const myArray &another)
{
    this->len = another.len;
    this->space = new int[this->len];
    for(int i = 0;i < another.len;i++){
        this->space[i] = another.space[i];
    }

    cout<<"myArray::myArray(const myArray &another)"<<endl;
}

myArray::~myArray()
{
    if(this->space == NULL){
        return;
    }
    //this->len = 0;
    delete[] this->space;
    this->space = NULL;
    this->len = 0;
    cout<<"myArray::~myArray()"<<endl;
}
void myArray::setData(int index,int data)
{
    if(index < 0 ||index >= this->len)
        return;
    if(this->space != NULL){
        this->index = index;
        this->space[index] = data;
    }
}
int myArray::getData(int index)
{
    this->index = index;
    return this->space[index];
}

int myArray::getLen()
{
    return this->len;
}
void myArray::setIndex(int index)
{
    this->index = index;
}
int myArray:: getIndex()
{
    return index;
}
void myArray::operator=(const myArray &another)
{
    this->len = another.len;
    this->space = new int[this->len];
    for(int i = 0;i < another.len;i++){
        this->space[i] = another.space[i];
    }

    cout<<"myArray::operator=(const myArray &another)"<<endl;
}

ostream &operator<<(ostream &os,const myArray &another)
{
    os<<"myArr["<<another.index<<"]"<<another.space[another.index];
    return os;
}
istream &operator>>(istream &is,myArray &another)
{
    cin>>another.space[another.index];
    return is;
}
