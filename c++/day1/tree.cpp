#include <iostream>
#include <string>
using namespace std;
class Tree{
private:
    int ages;
public:
    void set_ages(int age){
        this->ages = age;
    }
    int get_ages(){
        return ages;
    }
    string grow(){
        string s = to_string(ages) + "years";
        return s;
    }
};

int main()
{
    Tree t;
    t.set_ages(46);
    cout << "tree:"<<t.grow()<<endl;
    return 0;
}

