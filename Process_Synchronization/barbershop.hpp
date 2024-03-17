#ifndef barbershop
#define barbershop
#include"proc_sync_util.hpp"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h> // for usleep function
#include <iostream>
#define MAX_CUSTOMERS 25
using namespace std;  

void gethaircut(int id);
void cuthair();
void *customer(void* args);
void *barber(void * args);
void Barber_shop();

#endif