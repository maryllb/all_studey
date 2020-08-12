#include <iostream>
#include "myArray.h"
using namespace std;
int main()
{
    myArray myArr(10);
    for(int i = 0;i < 10;i++){
        myArr.setData(i,i+100);
        //cout<<"myArr["<<i<<"]:"<<myArr.getData(i)<<endl; 
        cout<<myArr<<endl;
    }
    //这是拷贝构造
    myArray myArr2 = myArr;
    //这是=操作符重载
    myArray myArr3;
    myArr3 = myArr;
    
    cout<<"-------"<<endl;
    //myArr2 = myArr;
    for(int i = 0;i < 10;i++){
        //myArr2.setData(i,i+100);
        //cout<<"myArr2["<<i<<"]:"<<myArr2.getData(i)<<endl; 
    cout<<myArr2<<endl;
    }
    int index;
    cout<<"input index"<<endl;
    cin>>index;
    myArr3.setIndex(index);
    cout<<"input val"<<endl;
    cin>>myArr3;
    cout<<myArr3<<endl;
    return 0;
}

