#ifndef dining_philsophers
#define dining_philsophers

#include"proc_sync_util.hpp"
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

class aargs{
    public:
        int id;
        int num;
};
int left(int id, int n);
int right(int id, int n);
void think(int id);
void eat(int id);
void *leftphilosopher(void* args);
void *rightphilosopher(void* args);
void Dining_phil();

#endif