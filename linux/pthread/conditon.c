#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


/*
 *  使用互斥量和条件变量实现生产者消费者模型
 *
 * 
 */
typedef struct node
{
    int data;
    struct node* next;
}Node;
//永远指向链表头部的指针
Node *head = NULL;

//线程同步--互斥锁
pthread_mutex_t mutex;
//阻塞线程-- 条件变量
pthread_cond_t cond;

void* producer(void* args)
{
    while(1){
        Node* pnew = (Node*)malloc(sizeof(Node));
        pnew->data = rand() % 1000;
        //使用互斥锁保护共享数据
        pthread_mutex_lock(&mutex);
        pnew->next = head;
        head = pnew;
        printf("----------producer %lu, %d----------\n",pthread_self(),pnew->data);
        pthread_mutex_unlock(&mutex);
    
        //通知阻塞的消费者线程，接触阻塞。
        pthread_cond_signal(&cond);

        sleep(rand() % 3);
    }


    return NULL;
}

void* customer(void* args)
{
    while(1){

        pthread_mutex_lock(&mutex);
        //判断链表是否为空
        if(head == NULL){
            //线程阻塞
            //该函数会对互斥锁解锁
            pthread_cond_wait(&cond,&mutex);

            //continue;
        }
        Node* pdel = head;
        head = head->next;
        printf("----------customer %lu, %d----------\n",pthread_self(),pdel->data);
        free(pdel);
        pthread_mutex_unlock(&mutex);

    }
    return NULL;
}

int main()
{
    //init
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
   
    pthread_t p1,p2;
    //创建生产者线程
    pthread_create(&p1,NULL,producer,NULL);
    //创建消费者线程
    pthread_create(&p2,NULL,customer,NULL);

    //阻塞回收子线程
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    //destroy 销毁
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;

}

