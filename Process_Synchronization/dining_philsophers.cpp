#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h> // for usleep function
#include <bits/stdc++.h>

#define MAX_PHIL 50
using namespace std;
//Global varibles 
sem_t forks_mutex[MAX_PHIL];
sem_t allphilcreated;
int max_eattime;
int max_thinktime;
class aargs{
    public:
        int id;
        int num;
};
int left(int id, int n){
    return (id + 1) % n;
}
int right(int id, int n){
    return id;
}
void think(int id){
    cout << "Philsopher " << id << " is thinking\n";
   
    
}
void eat(int id){
    cout << "Philsopher " << id << " has accquired both forks and is now eating\n";
    sleep(rand() % max_eattime);
    cout << "Philsopher " << id << " has finished eating\n";
}
void *leftphilosopher(void* args){
    sem_wait(&allphilcreated);
    int ID = ((aargs *)args)->id;
    int N = ((aargs *)args)->num;
    int l_id = left(ID,N);
    int r_id = right(ID,N);
    think(ID);
    cout << "Philsopher " << ID << " is now hungry\n";
    sem_wait(&forks_mutex[l_id]);
    cout << "Philosopher 0 has accuired left fork\n";
    sem_wait(&forks_mutex[r_id]);
    eat(ID);
    sem_post(&forks_mutex[l_id]);
    sem_post(&forks_mutex[r_id]);
    cout << "Philsopher 0 has given up both the forks\n";
    return NULL;
}
void *rightphilosopher(void* args){
    sem_wait(&allphilcreated);
    int ID = ((aargs *)args)->id;
    int N = ((aargs *)args)->num;
    int l_id = left(ID, N);
    int r_id = right(ID, N);
    think(ID);
    cout << "Philsopher " << ID << " is now hungry\n";
    sem_wait(&forks_mutex[r_id]);
    cout << "Philosopher " << ID << " has acquired his right fork\n";
    sem_wait(&forks_mutex[l_id]);
    eat(ID);
    sem_post(&forks_mutex[r_id]);
    sem_post(&forks_mutex[l_id]);
    cout << "Philsopher " << ID << " has given up both the forks\n";
    return NULL;
}
void dining_phil(){
    int n;
    cout << "Enter the number of philosophers: \n";
    cin >> n;
    cout << "Enter the maximum thinking time that a philsopher can have: \n";
    cin >> max_thinktime;
    cout << "Enter the maximum thinking time that a philsopher can have: \n";
    cin >> max_eattime;
    pthread_t phil_arr[n];
    aargs x[n];
    //create one leftphilsopher thread and rest of them as rightphilosphers
    x[0].id = 0;
    x[0].num = n;
    sem_init(&allphilcreated, 0 , 0);
    sem_init(&forks_mutex[0], 0, 1);
    pthread_create(&phil_arr[0], NULL, leftphilosopher, &x[0]);

    for(int i = 1; i < n; i++){
        sem_init(&forks_mutex[i], 0, 1);
        x[i].id = i;
        x[i].num = n;
        pthread_create(&phil_arr[i], NULL, rightphilosopher, &x[i]); 
    }

    cout << "dining philosophers created \n";
    for(int i = 0; i < n; i++){
        sem_post(&allphilcreated);
    }
    for (int i=0; i<n; i++) pthread_join(phil_arr[i], NULL);
    cout << "all philsophers thread have finished and have joined the main thread\n";
}