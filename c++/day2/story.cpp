#include <iostream>
#include <unistd.h>

using namespace std;
class Goods
{
private:
    int weight;
    static int total_weight;
public:
    Goods* next;
    Goods(){
        weight = 0;
        next = NULL;
        cout<<"创建了一个重量为 "<<weight<<endl;
    }
    Goods(int w){
        weight = w;
        next = NULL;
        total_weight += weight;
        cout<<"创建了一个重量为 "<<weight<<endl;
    }
    ~Goods(){
        cout<<"仓库减少了重量为 "<<weight<<"的货物"<<endl;
        total_weight -= weight;
    }
    static int get_total_weight(){
        return total_weight;
    }

};
int Goods::total_weight = 0;
void buy(Goods* &head,int w)
{
    Goods* new_goods = new Goods(w);
    if(head == NULL){
        head = new_goods;
    }
    else{
        new_goods->next= head;
        head = new_goods;
    }

}
void sale(Goods* &head)
{
    if(head == NULL){
        cout<<"已经没有货物了"<<endl;
        return;
    }
    Goods* temp = head;
    head = head->next;
    delete temp;
    cout<<"sale."<<endl;

}

int main()
{
    int choice = 0;
    Goods* head = NULL;
    int w = 0;
    do{
        cout<<"1.进货"<<endl;
        cout<<"2.出货"<<endl;
        cout<<"0.退出"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"请输入货物的重量：";
            cin>>w;
            buy(head,w);
            break;
        case 2:
            sale(head);
            break;
        case 0:
            return 0;
        default:
            break;
        }        
        cout<<"货物的总重量为:"<<Goods::get_total_weight()<<endl;

    }while(1);
    return 0;
}

