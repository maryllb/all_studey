#include <iostream>
#include <unistd.h>
using namespace std;

/*
 * 根据类图，实现家庭影院外观模式应用。
 * 实现 KTV 模式：电视打开，灯关掉，音响打开，麦克风打开，dvd 打开；
 * 实现游戏模式：电视打开，音响打开，游戏机打开。
 * */


//电视
class Televison
{
public:
    void On(){
        cout<<"Televison already On"<<endl;
    }
    void Off(){
        cout<<"Televison already Off"<<endl;
    }
};
//灯
class Lamp
{
public:
    void On(){
        cout<<"Lamp already On"<<endl;
    }
    void Off(){
        cout<<"Lamp already Off"<<endl;
    }
};
//音响
class Audio
{
public:
    void On(){
        cout<<"Audio already On"<<endl;
    }
    void Off(){
        cout<<"Audio already Off"<<endl;
    }

};
//麦克风
class Microphone
{
public:
    void On(){
        cout<<"Microphone already On"<<endl;
    }
    void Off(){
        cout<<"Microphone already Off"<<endl;
    }
};
class Dvd
{
public:
    void On(){
        cout<<"Televison already On"<<endl;
    }
    void Off(){
        cout<<"Televison already Off"<<endl;
    }
};
class GameMachine
{
    void On(){
        cout<<"GameMachine already On"<<endl;
    }
    void Off(){
        cout<<"GameMachine already Off"<<endl;
    }
};
//外观抽象类
class AbstractMode
{
public:
    virtual void On() = 0;
    virtual void Off() = 0;
};

class KtvMode:public AbstractMode
{
public:
    KtvMode(){
        this->tel = new Televison;
        this->audio = new Audio;
        this->mcp = new Microphone;
        this->dvd = new Dvd;
    }
    virtual void On(){
        cout<<"Ktc mode On"<<endl;
        tel->On();
        audio->On();
        mcp->On();
        dvd->On();
    }
    virtual void Off(){
        cout<<"ktv mode Off"<<endl;
        tel->Off();
        audio->Off();
        mcp->Off();
        dvd->Off();

    }
private:
    Televison* tel;
    Audio* audio;
    Microphone* mcp;
    Dvd* dvd;

};

class GameMode:public AbstractMode
{
public:
    GameMode(){
        this->tel = new Televison;
        this->audio = new Audio;
        this->mcp = new Microphone;
    }
    virtual void On(){
        cout<<"game mode"<<endl;
        tel->On();
        audio->On();
        mcp->On();
    }
    virtual void Off(){
        cout<<"game mode Off"<<endl;
        tel->Off();
        audio->Off();
        mcp->Off();

    }
private:
    Televison* tel;
    Audio* audio;
    Microphone* mcp;
};
int main()
{
    AbstractMode* ktv = new KtvMode;
    ktv->On();
    ktv->Off();
    cout<<"------------"<<endl;
    AbstractMode* game = new GameMode;
    game->On();
    game->Off();

    return 0;
}

