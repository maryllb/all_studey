#include <iostream>
#include "Data.h"
#include <ctype.h> 
Data::Data()
{
    this->day = 01;
    this->month = 01;
    this->year = 2020;
}
Data::Data(int day,int month,int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
Data::Data(const Data & another)
{
    this->day = another.day;
    this->month = another.month;
    this->year = another.year;
}
int Data::getDay()
{
    return this->day;
}
int Data::getMonth()
{
    return this->month;
}
int Data::getYear()
{
    return this->year;
}
Data::~Data()
{
    cout<<"Data::~Data()"<<endl;
}

Data& Data::operator=(Data & another)
{
    this->day = another.day;
    this->month = another.month;
    this->year = another.year;
    return *this;
}
ostream& operator<<(ostream & os,Data &d)
{
    os<<d.year<<"年"<<d.month<<"月"<<d.day<<"日"<<endl;
    return os;
}
