#include"barbershop.hpp"

//Global variables
sem_t seats_mutex; // semaphore used as mutex for using the global variable seats
sem_t customers;   // semaphore used by barber to wait for the customers 
sem_t barbers;     // semaphore used by customers to wait for the barber 

int max_seats;     // total number of seats in the waiting area of the barbershop
int seats;         // number of seats filled in the shop
int alldone = 0;

void gethaircut(int id){
    sleep(3);
    cout<< BOLDYELLOW << "Customer " << BOLDWHITE << id << BOLDYELLOW << " is done with his haircut\n\n";
}

void cuthair(){
    sleep(3);
}


//Customer thread
void *customer(void* args){
    int id = *((int *)args);

    sem_wait(&seats_mutex); // Acquire the mutex of seats variable 

    if(seats == max_seats){
        cout << BOLDRED << "Customer " << BOLDWHITE << id << BOLDRED << " has left the shop without a haircut as the waiting area was full!!\n\n"; 
        sem_post(&seats_mutex); // release the mutex of seats variable
        return NULL;
    }
    else{
        seats++; // update the seats variable 
        sem_post(&seats_mutex); //release the mutex of seats variable
    }

    sem_post(&customers); // post the customer semaphore to let the barber know that the customer has arrived is waiting 

    cout << BOLDBLUE << "Customer " << BOLDWHITE << id << BOLDBLUE << " waits in the waiting room for the barber\n\n";

    sem_wait(&barbers); // wait for the barber to call (sleep till then)

    cout << BOLDBLUE << "Customer " << BOLDWHITE << id << BOLDBLUE << " gets called to the barber chair\n\n";
    
    sem_wait(&seats_mutex); 
    seats--;                //update the seats variable as the customer empties the seat.
    cout << BOLDRED << "Number of seats filled in the waiting area: " << BOLDWHITE << seats << "\n\n";
    sem_post(&seats_mutex);
    
   
    gethaircut(id); //finally get a haircut

    return NULL;
}


//barber thread
void *barber(void * args){
    // loops untill all the customers are done
    while(alldone == 0){
        
        sem_wait(&customers); // waits for the customers to arrive

        if(alldone == 1)
            return NULL;

        sem_post(&barbers);

        cuthair();
    }

    return NULL;
}



void Barber_shop(){
    pthread_t btid;// barber threads
    pthread_t tid[MAX_CUSTOMERS]; //customer threads

    int i, numCustomers;
    int Number[MAX_CUSTOMERS]; //array of id of customers
    int AT[MAX_CUSTOMERS]; //array of arrival time of customers
    func(4);
    cout << BOLDMAGENTA << "BARBER SHOP PROCESS SYNCHRONIZATION PROBLEM";
    func(2);
    cout << BOLDGREEN << "Enter the number of customers: " << BOLDWHITE;
    cin >> numCustomers;
    cout << BOLDGREEN << "Enter the number of seats in the waiting area: " << BOLDWHITE;
    cin >> max_seats;

    seats = 0;
    func(3);
    for (i = 0; i < numCustomers; i++) {
        cout << BOLDGREEN << "Enter Arrival Time for Customer " << BOLDWHITE <<  i << ": ";
        cin >> AT[i];
        Number[i] = i;
    }
   
    // Initialize the semaphores with initial values...
    sem_init(&customers, 0, 0);
    sem_init(&barbers, 0, 0);
    sem_init(&seats_mutex, 0, 1);


    func(4);
    // Create the barber.
    pthread_create(&btid, NULL, barber, NULL);
    cout << BOLDMAGENTA "Barber is ready and will sleep untill someone arrives and wakes him up";

    // Create the customers.
    int sl = AT[0];
    func(3);
    for (i = 0; i < numCustomers; i++){
        sleep(sl);
        pthread_create(&tid[i], NULL, customer, &Number[i]);
        cout << BOLDMAGENTA <<"Customer " << BOLDWHITE << i << BOLDMAGENTA << " has arrived at the barber shop at t = " <<  BOLDWHITE << AT[i] << "\n\n";
        
        if(i < numCustomers - 1)
            sl = AT[i+1] - AT[i];
    }
    
  
    
    for (int i=0; i<numCustomers; i++) pthread_join(tid[i], NULL);
    cout << BOLDGREEN << "All the customers have finished their haircuit\n";
    cout << BOLDBLACK << "The irregularties that might appear are due to unpredicatability in scheduling of the threads."; 
    // When all of the customers are finished, kill the barber thread.
    alldone = 1;
    sem_post(&customers);
 // Wake the barber so that he will exit.
    pthread_join(btid, NULL);

    
}