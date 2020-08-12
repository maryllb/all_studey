#include <iostream>

using namespace std;
/*
 *组装电脑有3个抽象类，抽象的cpu，抽象的显卡，抽象的内存。 
 *现在要求组装两台电脑，一台是Intel的CPU，Intel的显卡和Intel的内存。 
 *另一台是Intel的CPU、Nvidia的显卡和Kingston的内存条。针对抽象层编程
 *练习完成此题。
 * 
*/
/*-------抽象层-----*/
class Cpu
{
public:
    Cpu(){}
    virtual void caculate() = 0;
};
class Card
{
public:
    Card(){}
    virtual void display() = 0;
};
class Memory
{
public:
    Memory(){}
    virtual void storage() = 0;
};
/*-----------架构层-----------*/

class Computer
{
public:
    Computer(Cpu *cpu,Card *card,Memory *memory){
        this->cpu = cpu;
        this->card =  card;
        this->memory = memory;
    }
    void work(){
        cpu->caculate();
        card->display();
        memory->storage();
    }
    ~Computer(){
        if(this->cpu != NULL) delete this->cpu;
        if(this->card != NULL) delete this->card;
        if(this->memory != NULL) delete this->memory;
    }
private:
    Cpu *cpu;
    Card *card;
    Memory *memory;
};

/*----------实现层----------*/

class IntelCpu :public Cpu
{
public:
    virtual void caculate(){
        cout<<"Intel CPU开始计算了" << endl;
    }
};
class IntelCard :public Card
{
public:
    virtual void display(){
        cout<<"Intel Card开始显示了"<<endl;
    }
};
class InterMemory:public Memory
{
public:
    virtual void storage(){
        cout<<"Intel mem开始存储了" << endl;
    }
};
class NvidiaCard :public Card
{
public:
    virtual void display(){
        cout<<"Nvidia Card开始显示了"<<endl;
    }

};
class KingstonMemory :public Memory
{
public:
    virtual void storage(){
        cout<<"Kingson memory开始存储了" << endl;     
    }

};
/*--------业务层-----------*/
int main()
{
    Computer *c1 = new Computer(new IntelCpu,new IntelCard,new InterMemory);
    Computer *c2 = new Computer(new IntelCpu,new NvidiaCard,new KingstonMemory);
    c1->work();
    c2->work();
    return 0;
}

