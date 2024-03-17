#include"producer_consumer.hpp"
sem_t consumer;    //semaphore acting as a conditional variable for the producer waiting on the full buffer
sem_t producer;    //semaphore acting as a conditional variable for the consumer waiting on the empty buffer
sem_t buffermutex; //semaphore acting as a lock on the buffer 
// create a buffer 
Buffer::Buffer(int size){
    capacity = size;
    Node* temp;
    temp = new Node();
    head = temp;
    tail = head;
    for(int i = 2; i <= size; i++){
        temp->next = new Node();
        temp = temp->next;
    }
    temp->next = head;
}
// destruct the buffer
Buffer::~Buffer(){
    Node* current = head;
    Node* next;
    // Traverse the list and deallocate memory for each node
    do {
        next = current->next;
        delete current;
        current = next;
    } while (current != head);
    head = nullptr;
    tail = nullptr;
}
//add a element into buffer 
void Buffer::enqueue(int num){
    tail->val = num;
    tail = tail->next;
    curr_size++;
}
// pop and return the popped element of the buffer
int Buffer::dequeue(){
    int tmp = head->val;
    head = head->next;
    curr_size--;
    return tmp;
}
// returns the current size of the buffer filled 
int Buffer::bufferfilled(){
    return curr_size;
}
// Compare arrival time for sorting 
bool compare_atime(Thread a, Thread b){
    if(a.atime == b.atime){
        if(a.type == 'p')
            return true;
        else    
            return false;
    }
    return (a.atime < b.atime);
}
// Producer thread
void * Producer(void * args){
    Arguments *arg  = (Arguments *)args;
    int id  = arg->id;
    Buffer *buffer = arg->buf;
    sem_wait(&consumer);

    sem_wait(&buffermutex);
    //critical section of producer adding a value into the buffer tail
    buffer->enqueue(id);
    cout << BOLDYELLOW << "Producer " << BOLDWHITE << id << BOLDYELLOW << " has enqueued the event into the buffer.\n\n";
    sem_post(&buffermutex);
    
    sem_post(&producer);
    return NULL;
}
// Consumer thread
void* Consumer(void* args){
    Arguments *arg  = (Arguments *)args;
    int id  = arg->id;
    Buffer *buffer = arg->buf;
    sem_wait(&producer);

    sem_wait(&buffermutex);
    //critical section of consumer thread where it deals with the value at the head of the buffer
    int num  = buffer->dequeue();
    cout << BOLDRED << "Consumer " << BOLDWHITE << id << BOLDRED << " has consumed the event produced by Producer " << BOLDWHITE << num <<".\n\n";
    
    sem_post(&buffermutex);

    sem_post(&consumer);
    return NULL;
}
// main function of producer consumer function
void Producer_consumer(){
    int p,c,capacity;
    func(4);
    cout << BOLDMAGENTA << "PRODUCER CONSUMER PROCESS SYNCHRONIZATION PROBLEM";
    func(2);
    //take input
    cout << BOLDRED << "Let the number of producer threads >= number of consumer threads (for simplicity sake), else the program would not progress to finish!! \n\n";
    cout << BOLDGREEN << "Enter the number of producer threads: " << BOLDWHITE;
    cin >> p;
    cout << BOLDGREEN << "Enter the number of consumer threads: " << BOLDWHITE;
    cin >> c;
    cout << BOLDGREEN << "Enter the size of buffer: " << BOLDWHITE;
    cin >> capacity;
    func(3);
    vector<Thread> thread_arr(p+c);
    cout << BOLDGREEN << "Enter the arrival time of the " << BOLDWHITE << p << BOLDGREEN << " producer threads.\n\n";
    for(int i = 0; i < p; i++){
        thread_arr[i].id = i + 1;
        thread_arr[i].type = 'p';
        cout << BOLDGREEN << "Producer " << thread_arr[i].id << ": " << BOLDWHITE;
        cin >> thread_arr[i].atime;
       
    }
    func(3);
    cout << BOLDGREEN << "Enter the arrival time of the " << BOLDWHITE << c << BOLDGREEN << " consumer threads.\n\n";
    for(int i = 0; i < c; i++){
        thread_arr[p + i].id = i + 1;
        thread_arr[p + i].type = 'c';
        cout << BOLDGREEN << "Consumer " << thread_arr[p + i].id << ": " << BOLDWHITE;
        cin >> thread_arr[p + i].atime;
       
    }
    func(3);
    sort(thread_arr.begin(),thread_arr.end(), compare_atime);

    // intialize the sempahores
    sem_init(&consumer, 0, capacity); // waits for space in the buffer
    sem_init(&producer, 0, 0);// waits for the buffer to fill
    sem_init(&buffermutex, 0, 1);//mutex for buffer

    Buffer buffer = Buffer(capacity);

    // Create producer and consumer threads at arrival time
    int sleeptime = thread_arr[0].atime;
    Arguments arg;
    arg.buf = &buffer;
    for(int i = 0; i < p+c; i++){
        sleep(sleeptime);
        arg.id = thread_arr[i].id;
        
        if(thread_arr[i].type == 'p')
            pthread_create(&thread_arr[i].t, NULL, Producer, &arg);
        else
            pthread_create(&thread_arr[i].t, NULL, Consumer, &arg);
            
        if(i < p + c - 1)
            sleeptime = thread_arr[i + 1].atime - thread_arr[i].atime;
    }

    for(int i = 0; i < p+c; i++) pthread_join(thread_arr[i].t, NULL);
    func(3);
    cout << BOLDMAGENTA << "All the producer and consumer threads have finished and have joined the main process";


}

