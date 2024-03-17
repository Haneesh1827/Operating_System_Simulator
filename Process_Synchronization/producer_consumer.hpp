#ifndef producer_consumer
#define producer_consumer
#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<algorithm>
#include<vector>
#include<unistd.h>
#include"proc_sync_util.hpp"
using namespace std;
class Node{
    public:
    int val = 0;
    
    Node* next = NULL;
};
class Buffer{
    Node* head;
    Node* tail;
    int capacity;
    int curr_size = 0;
    public:
        Buffer(int size);
        ~Buffer();
        void enqueue(int num);
        int dequeue();
        int bufferfilled();
};
class Thread{
    public:
    pthread_t t;
    int id;
    int atime;
    char type;
};
class Arguments{
    public:
    Buffer *buf;
    int id;
};
bool compare_atime(Thread a, Thread b);
void* Producer(void* args);
void* Consumer(void* args);
void Producer_consumer();
#endif