#include <iostream>

using namespace std;
class Cube{
private:
    double high;
    double length;
    double width;
public:
    void set_High(double h){
        this->high = h;
    }
    void set_Length(double l){
        this->length =l;
    }
    void set_Width(double w){
        this->width = w;
    }
    double get_High(){
        return high;
    }
    double get_Length(){
        return length;
    }
    double get_Width(){
        return width;
    }
    bool judge(Cube c){
        if(c.get_High() == high && c.get_Width() == width && c.get_Length() == length){
            return true;
        }
        return false;
    }
    

};
int main()
{
    Cube c1,c2,c3;
    c1.set_High(3);
    c1.set_Width(4);
    c1.set_Length(5);
    
    c2.set_High(3);
    c2.set_Width(4);
    c2.set_Length(5);

    c3.set_High(3);
    c3.set_Width(4);
    c3.set_Length(7);
    if(c1.judge(c2)) cout<< "c1 和 c2 相等"<<endl;
    else cout << "c1 和 c2 不相等"<<endl;

    if(c1.judge(c3)) cout<< "c1 和 c3 相等"<<endl;
    else cout << "c1 和 c3 不相等"<<endl;
    return 0;
}

