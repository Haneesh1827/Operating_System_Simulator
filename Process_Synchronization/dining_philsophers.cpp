#include"dining_philsophers.hpp"
//global varibles 
sem_t forks_mutex[MAX_PHIL]; // mutex for forks
sem_t allphilcreated; //contional variable for philosophers threads to wait until all threads are created.
sem_t cout_mutex; //mutex for printing one at a time

int max_eattime;
int max_thinktime;

int left(int id, int n){
    return (id + 1) % n;  // returns the approiate fork id based on id of the thread
}
int right(int id, int n){
    return id;       // returns the approiate fork id based on id of the thread
}


void think(int id){
    sem_wait(&cout_mutex); cout << BOLDRED << "Philsopher " << BOLDWHITE << id << BOLDRED << " is thinking\n\n"; sem_post(&cout_mutex);

    if(max_thinktime > 0)
        sleep(rand() % max_thinktime);  //thinking
}

void eat(int id){
    sem_wait(&cout_mutex); cout << BOLDGREEN <<"Philsopher " << BOLDWHITE <<id << BOLDGREEN << " has accquired both forks and is now eating\n\n"; sem_post(&cout_mutex);

    if(max_eattime > 0)
        sleep(rand() % max_eattime); //eating

    sem_wait(&cout_mutex); cout << BOLDYELLOW "Philsopher " << BOLDWHITE << id << BOLDYELLOW << " has finished eating\n\n"; sem_post(&cout_mutex);
}

//picks left fork first
void *leftphilosopher(void* args){

    sem_wait(&allphilcreated); // wait till all threads are created, posted by main thread

    int ID = ((aargs *)args)->id; // unload the arguments
    int N = ((aargs *)args)->num;

    int l_id = left(ID,N); // get left and right forks id
    int r_id = right(ID,N);


    think(ID); //think


    sem_wait(&cout_mutex); cout << BOLDBLUE << "Philsopher "<< BOLDWHITE << ID << BOLDBLUE << " is now hungry\n\n" ; sem_post(&cout_mutex);

    sem_wait(&forks_mutex[l_id]); //wait for left fork first

    sem_wait(&cout_mutex); cout << BOLDGREEN "Philosopher 0 has accuired left fork\n\n"; sem_post(&cout_mutex);

    sem_wait(&forks_mutex[r_id]); //wait for right fork after left


    eat(ID); //eat


    sem_post(&forks_mutex[l_id]); // give up left fork 
    sem_post(&forks_mutex[r_id]); // give up right fork

    sem_wait(&cout_mutex); cout << BOLDWHITE "Philsopher 0 has given up both the forks\n\n"; sem_post(&cout_mutex);
    return NULL;
}

//picks right fork first
void *rightphilosopher(void* args){

    sem_wait(&allphilcreated);

    int ID = ((aargs *)args)->id;
    int N = ((aargs *)args)->num;

    int l_id = left(ID, N);
    int r_id = right(ID, N);


    think(ID); //thinking


    sem_wait(&cout_mutex); cout << BOLDBLUE << "Philsopher " << BOLDWHITE << ID << BOLDBLUE << " is now hungry\n\n"; sem_post(&cout_mutex);

    sem_wait(&forks_mutex[r_id]); //wait for right fork

    sem_wait(&cout_mutex); cout << BOLDGREEN << "Philosopher " << BOLDWHITE << ID << BOLDGREEN " has acquired his right fork\n\n"; sem_post(&cout_mutex);

    sem_wait(&forks_mutex[l_id]); //wait for left fork


    eat(ID); // eat


    sem_post(&forks_mutex[r_id]); //give up right fork 
    sem_post(&forks_mutex[l_id]); //give up left fork

    sem_wait(&cout_mutex); cout << BOLDWHITE << "Philsopher " << BOLDGREEN << ID << BOLDWHITE << " has given up both the forks\n\n"; sem_post(&cout_mutex);
    return NULL;
}


void Dining_phil(){
    func(5);
    cout << BOLDMAGENTA << "DINING PHILOSOPHERS SYNCHRONIZATION PROBLEM\n" << RESET;
    int n;
    func(2);
    cout << BOLDGREEN << "Enter the number of philosophers: \n" << BOLDWHITE;
    cin >> n;
    cout << BOLDGREEN << "Enter the maximum thinking time that a philsopher can have: \n" << BOLDWHITE;
    cin >> max_thinktime;
    cout << BOLDGREEN <<"Enter the maximum eating time that a philsopher can have: \n" << BOLDWHITE;
    cin >> max_eattime;


    pthread_t phil_arr[n]; //philosopher thread array
    aargs x[n]; //arguments array for those threads

    //create one leftphilsopher thread and rest of them as rightphilosphers
    x[0].id = 0;
    x[0].num = n; //no. of philosopher threads

    sem_init(&allphilcreated, 0 , 0);
    sem_init(&forks_mutex[0], 0, 1);
    sem_init(&cout_mutex, 0, 1);
    func(5);
    //create left phil
    pthread_create(&phil_arr[0], NULL, leftphilosopher, &x[0]);
    //create right phils
    for(int i = 1; i < n; i++){
        sem_init(&forks_mutex[i], 0, 1);
        x[i].id = i;
        x[i].num = n;
        pthread_create(&phil_arr[i], NULL, rightphilosopher, &x[i]); 
    }

    sem_wait(&cout_mutex); cout << BOLDMAGENTA << "Dining philosophers created \n\n\n" << RESET; sem_post(&cout_mutex);
    // wakeup all the phils
    for(int i = 0; i < n; i++){
        sem_post(&allphilcreated);
    }
    //join all the threads 
    for (int i=0; i<n; i++) pthread_join(phil_arr[i], NULL);
    
    cout << BOLDMAGENTA <<"\n\nAll philsophers thread have finished and have joined the main thread\n" << RESET;
}