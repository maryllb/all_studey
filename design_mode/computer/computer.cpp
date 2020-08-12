#include <iostream>
using namespace std;
/*
 * 设计一个电脑主板架构，电脑包括（显卡，内存，CPU）3个固定的插口，
 * 显卡具有显示功能（display，功能实现只要打印出意义即可）， 
 * 内存具有存储功能（storage），
 * cpu具有计算功能（calculate）。
 * 现有Intel厂商，nvidia厂商，Kingston厂商，均会生产以上三种硬件。要求组装两台电脑：
 * 1台（Intel的CPU，Intel的显卡，Intel的内存）
 * 1台（Intel的CPU， nvidia的显卡，Kingston的内存）
 * 用抽象工厂模式实现。
 * 
 * */
/*抽象产品角色*/
//抽象cpu
class AbstractCpu
{
public:
    virtual void calculate() = 0;
};
//抽象显卡
class AbstractCard
{
public:
    virtual void dispaly() =0;
};
//抽象内存
class AbstractMemory
{
public:
    virtual void storage() = 0;
};
/*具体产品角色*/
//intercpu
class IntelCpu:public AbstractCpu
{
    virtual void calculate(){
        cout<<"intel cpu calculate"<<endl;
    }
};
//intelcard
class IntelCard:public AbstractCard
{
    virtual void dispaly(){
        cout<<"intel card display"<<endl;
    }
};
//intermemory
class IntelMemory:public AbstractMemory
{
    virtual void storage(){
        cout<<"intel memory storage"<<endl;
    }
    ~IntelMemory(){
        cout<<"~IntelMemory()"<<endl;
    }
};
//nvidiacard
class NvidiaCard:public AbstractCard
{
    virtual void dispaly(){
        cout<<"nvidia card display"<<endl;
    }
};
//kindstonmemory
class KingstonMemory:public AbstractMemory
{
    virtual void storage(){
        cout<<"kingston memory storage"<<endl;
    }
};

/*抽象工厂角色*/
class AbstractFactory
{
public:
    virtual AbstractCpu* CreateCpu() = 0;
    virtual AbstractCard* CreateCard() = 0;
    virtual AbstractMemory* CreatMemory() = 0;
};
/*具体工厂角色*/
class IntelFactory: public AbstractFactory
{
public:
    virtual AbstractCpu* CreateCpu(){
        return new IntelCpu;
    }
    virtual AbstractCard* CreateCard(){
        return new IntelCard;
    }
    virtual AbstractMemory* CreatMemory(){
        return new IntelMemory;
    }
};

class NividaFactory: public AbstractFactory
{
public:
    virtual AbstractCpu* CreateCpu(){
        cout <<"no this cpu"<<endl;
        return NULL;
    }
    virtual AbstractCard* CreateCard(){
        return new NvidiaCard;
    }
    virtual AbstractMemory* CreatMemory(){
        cout <<"no this memory"<<endl;
        return NULL;
    }
};

class KingstonFactory: public AbstractFactory
{
public:
    virtual AbstractCpu* CreateCpu(){
        cout<<"no this cpu"<<endl;
        return NULL;
    }
    virtual AbstractCard* CreateCard(){
        cout<<"no this card"<<endl;
        return NULL;
    }
    virtual AbstractMemory* CreatMemory(){
        return new KingstonMemory;
    }
};
class Computer
{
public:
    Computer(AbstractCpu* &cpu,AbstractCard* &card,AbstractMemory* &memory){
        cpu->calculate();
        card->dispaly();
        memory->storage();
        delete cpu;
        delete card;
        delete memory;
    }
};

int  main()
{
    AbstractFactory* factory = NULL;
    AbstractCpu* cpu = NULL;
    AbstractCard* card = NULL;
    AbstractMemory* memory = NULL;
    factory = new IntelFactory();
    cpu = factory->CreateCpu();
    card = factory->CreateCard();
    memory = factory->CreatMemory();
    Computer(cpu,card,memory);
    return 0;
}
