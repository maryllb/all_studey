#include <iostream>
#include "MyString.h"
#include <string.h>
using namespace std;

MyString::MyString()
{
    this->s = NULL;
    this->len = 0;
}
MyString::MyString(const char* s)
{
    if(s == NULL){
        this->len = 0;
        this->s = new char[0 + 1];
        strcpy(this->s,"");
    }
    this->len = strlen(s);
    this->s = new char[this->len + 1];
    strcpy(this->s,s);
    cout<<"MyString::MyString(const char* s)"<<endl;
}
MyString::MyString(const MyString & another)
{
    this->len = another.len;
    this->s = new char[this->len + 1];
    strcpy(this->s,another.s);
    cout<<"MyString::MyString(const MyString & another)"<<endl;
}
int MyString::getLen()
{
    return this->len;
}
MyString& MyString:: operator=(const MyString & another)
{
    this->len = another.len;
    this->s = new char[this->len + 1];
    strcpy(this->s,another.s);
    cout<<"MyString& MyString:: operator=(const MyString & another)"<<endl;    
    return *this;
}
MyString MyString::operator+(const MyString & another)
{
    MyString temp;
    int len = this->len + another.len;
    temp.len = len;
    temp.s = new char[temp.len + 1];
    memset(temp.s,0,temp.len + 1);
    strcat(temp.s,this->s);
    strcat(temp.s,another.s);
    return temp;
}
bool MyString::operator==(const MyString & another)
{
    if(this->len != another.len) return false;
    if(!strcmp(this->s,another.s)) return false;
    return true;
}
bool MyString::operator!=(const MyString & another)
{
    if(this->len != another.len) return true;
    if(!strcmp(this->s,another.s)) return true;
    return false;
}
bool MyString::operator>(const MyString & another)
{
    if(this->len > another.len) return true;
    return false;
}
bool MyString::operator<(const MyString & another)
{
    if(this->len < another.len) return true;
    return false;
}
char& MyString::operator[](int index)
{
    return this->s[index];
}
ostream& operator<<(ostream &os,MyString & another)
{
    os<<another.s;
    return os;
}
istream& operator>>(istream & is,MyString & another)
{
    if(another.s != NULL){
        delete another.s;
        another.s = NULL;
        another.len = 0;
    }
    char temp[4*1024] = {0};
    cin>>temp;
    another.len = strlen(temp);
    another.s = new char[another.len+1];
    strcpy(another.s,temp);
    return is;
}

MyString::~MyString()
{
    cout<<"MyString::~MyString()"<<endl;
}
