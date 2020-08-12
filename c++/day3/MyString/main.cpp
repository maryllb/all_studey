#include <iostream>
#include "MyString.h"
using namespace std;
int main()
{
    MyString s1("qingyizhu");
    MyString s2 = s1;
    for(int i = 0;i < s1.getLen();i++) cout<<s1[i]<<" ";
    cout<<endl;
    cout<<"s2:"<<s2<<endl;
    MyString s3;
    s3 = s1;
    cout<<"s3:"<<s3<<endl;
    cout<<"-----------------------"<<endl;
    MyString s4("heyiling");
    if(s1==s4) cout<<s1<<" != "<<s4<<endl;
    else if(s1>s4) cout<<s1 <<" > "<<s4<<endl;
    else if(s1<s4) cout<<s1 <<" < "<<s4<<endl;
    cout<<"-----------------------"<<endl;
    
    return 0;
}

