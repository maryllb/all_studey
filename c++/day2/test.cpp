#include<iostream>

using namespace std;
class Test{
private:
    int val;
public:
    Test(){
        val = 0;
    }
    Test(int val){
        this->val = val;
        cout<<"Test(int val)"<<endl;
    }
    Test(const Test & another){
        this->val = another.val;
        cout<<"Test(const Test & another)"<<endl;
    }
    ~Test(){
        cout<<"~Test()"<<endl;
    }
    int get_val(){
        return this->val;
    }
};
int main(void)
{
    Test t1(100);
    Test t2 = t1;
    cout<<"t2:"<<t2.get_val()<<endl;
}
