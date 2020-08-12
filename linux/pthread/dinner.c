#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
pthread_mutex_t mutex[5];

void* dinner(void* arg)
{
    int num = (int)arg;
    int left,right;
    if(num < 4){
        //前四个人右手拿自己筷子
        right = num;
        left = right + 1;
    }
    else if(num == 4){
        //最后一个人左手拿自己筷子
        right = 0;
        left = num;
    }
    while(1){
        //右手加锁
        pthread_mutex_lock(&mutex[right]);
        //左手尝试加锁
        if(pthread_mutex_trylock(&mutex[left]) == 0){
            //吃饭
            printf("%c 正在吃面。。。。。。\n", num+'A');
            //左手解锁
            pthread_mutex_unlock(&mutex[left]);
        }
        //右手解锁
        pthread_mutex_unlock(&mutex[right]);
        sleep(rand() % 5);
    }
}
int main()
{
    pthread_t p[5];
    //init
    for(int i = 0;i < 5;i++) pthread_mutex_init(&mutex[5],NULL);
    //create
    for(int i = 0;i < 5;i++) pthread_create(&p[i],NULL,dinner,(void*)i);
    //join
    for(int i = 0;i < 5;i++) pthread_join(p[i],NULL);
    //destroy
    for(int i = 0;i < 5;i++) pthread_mutex_destroy(&mutex[i]);
    return 0;
}

