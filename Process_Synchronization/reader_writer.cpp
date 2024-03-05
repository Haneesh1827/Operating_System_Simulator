#include<semaphore.h>
#include<pthread.h>
#include<iostream>
using namespace std;
sem_t gate;
sem_t roomempty;

class ReaderSwitch{
    int counter;
    sem_t countermutex;
    public: 
    ReaderSwitch();
    void On();
    void Off();
};
ReaderSwitch::ReaderSwitch(){
    counter = 0;
    sem_init(&countermutex, 0, 1);
}
void ReaderSwitch::On(){
    sem_wait(&countermutex);
        counter += 1;
        if(counter == 1)
            sem_wait(&roomempty);
    sem_post(&countermutex);
}
void ReaderSwitch::Off(){
    sem_wait(&countermutex);
        counter -= 1;
        if(counter == 0)
            sem_post(&roomempty);
    sem_post(&countermutex);
}

ReaderSwitch obj;
void* Reader(void* args){
    sem_wait(&gate);
    sem_post(&gate);

    obj.On();
    //critical section of writer 
    obj.Off();
    return NULL;
}
void* Writer(void* args){
    sem_wait(&gate);

    sem_wait(&roomempty);
    //crtical section of writer
    sem_post(&roomempty);

    sem_post(&gate);
    return NULL;
}


