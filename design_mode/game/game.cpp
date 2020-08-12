#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
/*
 * 1 定义真实玩家(李逍遥) 
 * 2 定义代理玩家
 * 3 代理玩家代替李逍遥打怪升级
*/
class AbstractPlayer
{
public:
    virtual ~AbstractPlayer(){}
    virtual void levelup() = 0;
    virtual string getName() = 0;
    virtual int getLevel() = 0;
protected:
    string name;
    int level;
};

class Player:public AbstractPlayer
{
public:
    Player(string name){
        this->name = name;
        this->level = 1;
    }
    virtual ~Player(){

    }
    virtual void levelup(){
        this->name = name;
        cout<<this->name<<"正在打怪升级 "<<this->name<<"等级为："<<this->level<<endl;;
        this->level++;
        sleep(1);
    }
    virtual string getName(){
        return this->name;
    }
    virtual int getLevel(){
        return this->level;
    }
private:

};
class autoPlayer:public AbstractPlayer
{
public:
    autoPlayer(AbstractPlayer* player){
        this->player = player;
    }
    virtual ~autoPlayer(){}

    virtual void levelup(){
        cout<<"代理玩家正在帮"<<this->player->getName()<<"升级 ";
        cout<<"等级为："<<this->player->getLevel()<<endl;
        player->levelup();
    }
    virtual string getName(){
        return this->player->getName();
    }
    virtual int getLevel(){
        return this->player->getLevel();
    }
private:
    AbstractPlayer* player;
};

int main()
{
    AbstractPlayer* player = new Player("李逍遥");
    AbstractPlayer* autoplayer = new autoPlayer(player);

    for(int i = 0;i < 50;i++){
        player->levelup();
    }
    for(int i = 0;i < 50;i++){
        autoplayer->levelup();
    }

    delete player;
    delete autoplayer;
    return 0;
}

