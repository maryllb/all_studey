#include <iostream>
using namespace std;

/*
 *  设计一个基类Shape包含成员函数Show(), 将Show()声明为纯虚函数。
 *  Shape类公有派生矩形类Square（正方形）和圆类Circle（圆形）， 
 *  问题1： 分别定义Show()实现其主要集合元素的显示。使用抽象类Shape
 *  类型的指针，当它指向某个派生类的对象时，就可以通过访问该对象的虚函数
 *  成员Show()。 
 *  问题2：用ShowArea()分别显示各种图形的面积.最后还要显示所有图形
 *  的各个面积。要求积累指针数组，数组的每个元素指向一个派生类对象。
 * */



/*-------抽象层--------*/
class Shape
{
public:
    Shape(){
        cout << "Shape()"<<endl;
    }
    virtual ~Shape(){
        cout << "~Shape()"<<endl;
    }
    virtual double getArea() = 0;
    virtual void Show() = 0;
};

class Circle:public Shape
{
public:
    Circle(double r){
        this->r = r;
    }
    ~Circle(){
        cout << "~Circle"<<endl;
    }
    virtual double getArea(){
        return 3.14*this->r*this->r;
    }
    virtual void Show(){
        cout << "circle R:"<<this->r<<endl;
        cout << "circle "<<endl;
    }
private:
    double r;
};
class Square:public Shape
{
public:
    Square(double l){
        this->l = l;
    }
    ~Square(){
        cout<<"~Square"<<endl;
    }
    virtual double getArea(){
        return this->l*this->l;
    }
    virtual void Show(){
        cout<<"Square: L :"<<this->l<<endl;
    }
private:
    double l;
};
int main()
{
    Shape *arr[2] = {0};
    int r;
    cout<<"请输入圆的半径:"<<endl;
    cin>>r;
    arr[0] = new Circle(r);
    int l;
    cout<<"请输入正方形的边长:"<<endl;
    cin>>l;
    arr[1] = new Square(l);

    for (int i = 0; i < 2; i++) {
        arr[i]->Show();
        cout << arr[i]->getArea() << endl;

        delete arr[i];

    }
    return 0;
}

