#pragma once
#include<iostream>
#include<string>
using namespace std;
/*---抽象类----*/
class Employee
{
public:
    Employee();
    virtual ~Employee();
    //人员初始化
    virtual void init(string name) = 0;
    //升级
    virtual void uplevel(int level) = 0;
    //获取薪资
    virtual double getsalary() = 0;
    //显示员工信息
    void display();
protected:
    string name;
    int level;
    double salary;
    int id;
    static int startNum;
};

