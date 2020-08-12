#pragma once
#include <string>
/*
 *   自定义字符串类
 *
*/
using namespace std;
class MyString
{
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString & another);
    int getLen();
    MyString& operator=(const MyString & another);
    MyString operator+(const MyString & another);
    bool operator==(const MyString & another);
    bool operator!=(const MyString & another);
    bool operator>(const MyString & another);//仅仅比较长度，非ASCII
    bool operator<(const MyString & another);
    char & operator[](int index);
    friend ostream& operator<<(ostream & os,MyString & another);
    friend istream& operator>>(istream & is,MyString & another);
    ~MyString();

private:
    char* s;
    int len;
};

