#ifndef reader_writer
#define reader_writer
#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<vector>
#include<unistd.h>
#include<algorithm>
#include<cstdlib>
#include"proc_sync_util.hpp"
using namespace std;
class ReaderSwitch{
    int counter;
    sem_t countermutex;
    public: 
    ReaderSwitch();
    void On();
    void Off();
};
class thread{
    public:
    pthread_t t;
    int id;
    int atime;
    char type;
};
class arguments{
    public:
    int id;
};
bool Compare_atime(thread a, thread b);
void* Reader(void* args);
void* Writer(void* args);
void Reader_writer();
#endif