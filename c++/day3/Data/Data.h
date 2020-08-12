#pragma once
#include <iostream>
#include <ctype.h>

using namespace std;

/*
 *  定义一个处理日期的类 TDate,它有 3 个私有数据成员:Month,Day,Year 和若干个 公
 *  有成员函数,并实现如下要求: 
 *  1构造函数重载 
 *  2成员函数设置缺省参数 
 *  3可使用不同的构造函数来创建不同的对象 
 *  4定义一个友元函数来打印日期
 */
class Data
{
public:
    Data();
    Data(int day,int month,int year = 2020);
    Data(const Data & another);
    int getDay();
    int getMonth();
    int getYear();
    ~Data();
    Data& operator=(Data & another);
    friend ostream& operator<<(ostream & os,Data &d);

private:
    int day;
    int month;
    int year;
};

