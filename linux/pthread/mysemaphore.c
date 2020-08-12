#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

sem_t producer_sem;
sem_t customer_sem;
typedef struct node
{
    int data;
    struct node* next;

}Node;
//永远指向链表头部的指针
Node *head = NULL;

void* producer(void* arg)
{
    while(1)
    {
        sem_wait(&producer_sem);     // porduce_sem --  == 0, 阻塞
        Node * node = (Node*)malloc(sizeof(Node));
        node->data = rand() % 1000;
        node->next = head;
        head = node;
        printf("+++++ 生产者：%lu, %d\n", pthread_self(), node->data);
        sem_post(&customer_sem);  // custom_sem++

        sleep(rand()%5);

    }
    return NULL;
}

void* customer(void* arg)
{
    while(1)
    {
        sem_wait(&customer_sem);
        Node* del = head;
        head = head->next;
        printf("----- 消费者：%lu, %d\n", pthread_self(), del->data);
        free(del);
        sem_post(&producer_sem);

        sleep(rand()%5);

    }
    return NULL;
}

int main()
{
    pthread_t thid[4];
    //init
    sem_init(&producer_sem,0,4);// porduce_sem --  == 0, 阻塞 
    sem_init(&customer_sem,0,0);

    pthread_create(&thid[0], NULL, producer, NULL);
    pthread_create(&thid[1], NULL, producer, NULL);
    pthread_create(&thid[2], NULL, producer, NULL);
    pthread_create(&thid[3], NULL, customer, NULL);
    for(int i=0; i<4; ++i)
    {
        pthread_join(thid[i], NULL);

    }

    sem_destroy(&producer_sem);
    sem_destroy(&customer_sem);
    return 0;
}

