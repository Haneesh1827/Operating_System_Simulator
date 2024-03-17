
#include"reader_writer.hpp"
sem_t gate;
sem_t roomempty;

int arr[4];
bool Compare_atime(thread a, thread b){
    if(a.atime == b.atime){
        if(a.type == 'r')
            return false;
        else    
            return true;
    }
    return (a.atime < b.atime);
}
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
    arguments* arg = (arguments*)args;
    int id = arg->id;
    sem_wait(&gate);
    sem_post(&gate);
    cout << BOLDCYAN << "Reader " << BOLDWHITE << id << BOLDCYAN << " has entered the lobby and now will have to wait for the room to get empty if occupied by writer\n\n" << RESET;
    obj.On();
    //critical section of writer 
    cout << BOLDYELLOW << "Reader " << BOLDWHITE << id << BOLDYELLOW <<" will now read the data avialble in the global vector:  " << BOLDWHITE;
    for(int i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << RESET;
    cout << "\n\n";
    sleep(1);
    //crtical section ends
    obj.Off();
    return NULL;
}
void* Writer(void* args){

    arguments* arg = (arguments*)args;
    int id = arg->id;

    sem_wait(&gate);
    
    cout << BOLDCYAN << "\nWriter " << BOLDWHITE << id << BOLDCYAN << " has accquired the gate semaphore and will now have to accquire the roomempty semaphore.\n\n" << RESET;   
    sem_wait(&roomempty);
    //crtical section of writer
    cout << BOLDCYAN << "Writer " << BOLDWHITE << id << BOLDCYAN << " has entered the room (Critical section)\n" << RESET;
    int random = rand() % 4;
    random --;
    arr[random]++;
    cout << BOLDRED << "Writer " << BOLDWHITE << id << BOLDRED << " has written something in the array vector.\n\n" << RESET;
    sleep(1);
    //critical section ends
    sem_post(&roomempty);

    sem_post(&gate);
    return NULL;
}
void Reader_writer(){
    func(6);
    cout << BOLDMAGENTA << "READERS AND WRITERS PROCESS SYNCHRONIZATION PROBLEM\n\n" << RESET;
    int w,r;
    for(int i=0; i<4 ; i++) arr[i] = 0;
    //take input
    cout << BOLDGREEN << "Enter the number of writer threads: " << BOLDWHITE;
    cin >> w;
    cout << BOLDGREEN << "Enter the number of reader threads: " << BOLDWHITE;
    cin >> r;
     
    vector<thread> thread_arr(w+r);
    cout << BOLDGREEN << "\n\nEnter the arrival time of the " << BOLDWHITE << w << BOLDGREEN << " writer threads.\n" << BOLDWHITE;
    for(int i = 0; i < w; i++){
        thread_arr[i].id = i + 1;
        thread_arr[i].type = 'w';
        cout << BOLDGREEN << "\nWriter " << BOLDWHITE << thread_arr[i].id << BOLDGREEN <<": " << BOLDWHITE; 
        cin >> thread_arr[i].atime;
        
    }
    cout << BOLDGREEN <<"\n\nEnter the arrival time of the " << BOLDWHITE << r << BOLDGREEN << " reader threads." << BOLDWHITE;
    for(int i = 0; i < r; i++){
        thread_arr[w+i].id = i + 1;
        thread_arr[w+i].type = 'r';
        cout << BOLDGREEN << "\nReader " << BOLDWHITE << thread_arr[w+i].id << BOLDGREEN <<": " << BOLDWHITE;
        cin >> thread_arr[w+i].atime; 
    }
    sort(thread_arr.begin(), thread_arr.end(), Compare_atime);
    sem_init(&gate, 0, 1);
    sem_init(&roomempty, 0, 1);

    int sleeptime = thread_arr[0].atime;
    arguments arg;
    func(3);
    for(int i = 0; i < w+r; i++){
        sleep(sleeptime);
        arg.id = thread_arr[i].id;
        
        if(thread_arr[i].type == 'w')
            pthread_create(&thread_arr[i].t, NULL, Writer, &arg);
        else
            pthread_create(&thread_arr[i].t, NULL, Reader, &arg);
    }
    for(int i = 0; i < w+r; i++) pthread_join(thread_arr[i].t, NULL);
    cout << BOLDBLUE << "\nAll the writer and reader threads have finished their work and have joined the main thread\n\n" << RESET;  
}


