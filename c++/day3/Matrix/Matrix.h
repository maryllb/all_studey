#pragma once
#include<iostream>
using namespace std;
/*
 *  设计一个 3*3 的矩阵类 class Matrix,通过一数组进行初始化。
 *  要求如下: 
 *  1默认构造(初始化为 0),有参构造(数组作实参)
 *  2重载+ / +=
 *  3重载* / *= 
 *  4实现输出
 *
*/
class Matrix
{
public:
    Matrix();
    Matrix(int (*p)[3]);
    ~Matrix();
    Matrix operator+(const Matrix & another);
    Matrix& operator+=(const Matrix & another);
    Matrix operator*(const Matrix & another);
    Matrix& operator*=(const Matrix & another);
    friend ostream& operator<<(ostream& os,Matrix m);
private:
    int data[3][3];
};

