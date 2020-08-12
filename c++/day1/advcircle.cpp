#include <iostream>
#include <math.h>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    void set_xy(int x,int y){
        this->x = x;
        this->y = y;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
};

class AdvCircle{
private:
    Point t;
    double r;
public:
    void set_Point(int x,int y){
        t.set_xy(x,y);
    }
    void set_Radius(double r){
        this->r = r;
    }
    bool judge(Point p){
        if(pow(p.get_x()-t.get_x(),2) +pow( p.get_y()-t.get_y(),2) < pow(r,2)){
            return true;
        }
        return false;
    }
    
};



int main()
{
    Point p;
    AdvCircle c;
    p.set_xy(5,8);
    c.set_Point(2,1);
    c.set_Radius(3);
    if(c.judge(p)) cout<< " p 在 c 内"<<endl;
    else cout << " p 不在 c 内"<<endl;
    return 0;
}

