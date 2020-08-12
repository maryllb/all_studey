#include <iostream>

using namespace std;
class Circle{
private:
    double r;
public:
    void set_Radius(double r){
        this->r = r;
    }
    double get_Radius(){
        return r;
    }
    double get_Girth(){
        return 2*3.14f*r;
    }
    double get_Area(){
        return 3.14f*r*r;
    }
};


int main()
{
    Circle c1;
    c1.set_Radius(2.0);
    cout<< "Radius:"<< c1.get_Radius()<<endl;
    cout<< "Girth:"<< c1.get_Girth()<<endl;
    cout<< "Area:"<< c1.get_Area()<<endl;
    return 0;
}

