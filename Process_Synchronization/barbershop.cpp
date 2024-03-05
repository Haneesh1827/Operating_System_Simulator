#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h> // for usleep function
#include <bits/stdc++.h>
#define MAX_CUSTOMERS 25

using namespace std; 

//Global variables
sem_t seats_mutex; // semaphore used as mutex for using the global variable seats
sem_t customers;   // semaphore used by barber to wait for the customers 
sem_t barbers;     // semaphore used by customers to wait for the barber 

int max_seats;     // total number of seats in the waiting area of the barbershop
int seats;         // number of seats filled in the shop
int alldone = 0;
void gethaircut(int id){
    sleep(3);
    cout<< "Customer" << id << "is done with his haircut" << '\n';
}
void cuthair(){
    sleep(3);
    cout<< "Barber has the finished the haircut of the present customer"<< '\n';
}
//Customer thread
void *customer(void* args){
    int id = *((int *)args);
    cout << "Customer" << id << " has arrived."<< '\n';
    sem_wait(&seats_mutex);
    if(seats == max_seats){
        sem_post(&seats_mutex);
        return NULL;
    }
    else{
        seats++;
        sem_post(&seats_mutex);
    }
    sem_post(&customers);
    cout << "Customer" << id << " waits in the waiting room for the barber"<< '\n';
    sem_wait(&barbers);
    cout << "Customer" << id << " gets called into the barber chair"<< '\n';
    
    sem_wait(&seats_mutex);
    
    seats--;

    sem_post(&seats_mutex);
    
    cout << "Number of seats filled in the waiting area: " << seats << '\n';
    gethaircut(id);
    return NULL;
}
//barber thread
void *barber(void * args){
    while(alldone == 0){
        
        sem_wait(&customers);
        if(alldone == 1)
            return NULL;
        cout << "barber calls a customer waiting in the room to the barber chair"<< '\n';
        sem_post(&barbers);
        cuthair();
    }
    return NULL;
}

void barbershop(){
    pthread_t btid;
    pthread_t tid[MAX_CUSTOMERS];
    int i, numCustomers;
    int Number[MAX_CUSTOMERS];
    int AT[MAX_CUSTOMERS];
    cout << "Enter the number of customers and chairs: "<< '\n';
    cin >> numCustomers;
    cin >> max_seats;
    seats = 0;
    for (i = 0; i < numCustomers; i++) {
        cout << "Enter Arrival Time for Customer " << i << ": "<< '\n';
        cin >> AT[i];
        Number[i] = i;
    }
   
    // Initialize the semaphores with initial values...
    sem_init(&customers, 0, 0);
    sem_init(&barbers, 0, 0);
    sem_init(&seats_mutex, 0, 1);
   
    // Create the barber.
    pthread_create(&btid, NULL, barber, NULL);
    cout << "barber is ready"<< '\n';
     // Create the customers.
    
    int sl = AT[0];
    for (i = 0; i < numCustomers; i++){
        sleep(sl);
        cout << "Customer" << i << "has arrived at the barber shop at t = " << AT[i] << '\n';
        pthread_create(&tid[i], NULL, customer, &Number[i]);
        
        if(i<numCustomers - 1)
            sl = AT[i+1] - AT[i];
    }
    
  
    
    for (int i=0; i<numCustomers; i++) pthread_join(tid[i], NULL);
    cout << "all the customers have finished their haircuit\n";
    // When all of the customers are finished, kill the barber thread.
    alldone = 1;
    sem_post(&customers);
 // Wake the barber so he will exit.
    pthread_join(btid, NULL);

    
}