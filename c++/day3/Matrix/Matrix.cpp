#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            this->data[i][j] = 0;
        }
    }
}
Matrix::Matrix(int (*p)[3])
{
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            this->data[i][j] = p[i][j];
        }
    }
}
Matrix::~Matrix()
{
    cout<<"Matrix::~Matrix()"<<endl;
}
Matrix Matrix::operator+(const Matrix & another)
{
    Matrix temp;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            temp.data[i][j] = this->data[i][j] + another.data[i][j];
        }
    }
    return temp;
}
Matrix& Matrix::operator+=(const Matrix & another)
{
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            this->data[i][j] += another.data[i][j];
        }
    }
    return *this;

}
Matrix Matrix::operator*(const Matrix & another)
{
    Matrix temp;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            temp.data[i][j] = this->data[i][j] * another.data[i][j];
        }
    }
    return temp;
}
Matrix& Matrix::operator*=(const Matrix & another)
{
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            this->data[i][j] *= another.data[i][j];
        }
    }
    return *this;
}
ostream& operator<<(ostream& os,Matrix m)
{
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            os<<m.data[i][j]<<" ";
        }
    os<<endl;
    }
    
    return os;
}
