#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;

sem_t consumer;
sem_t producer;
sem_t buffermutex;

class Node{
    public:
    int val = 0;
    Node* next = NULL;
};

class buffer{
    Node* head;
    Node* tail;
    int capacity;
    int curr_size = 0;
    public:
        buffer(int size);
        ~buffer();
        void enqueue(int num);
        int dequeue();
        int bufferfilled();
};
buffer::buffer(int size){
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
buffer::~buffer(){
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
void buffer::enqueue(int num){
    tail->val = num;
    tail = tail->next;
    curr_size++;
}
int buffer::dequeue(){
    int tmp = head->val;
    head = head->next;
    curr_size--;
    return tmp;
}
int buffer::bufferfilled(){
    return curr_size;
}

void * Producer(void * args){
    sem_wait(&consumer);
    sem_wait(&buffermutex);
    //critical section of producer adding a value into the buffer tail
    sem_post(&buffermutex);
    sem_post(&producer);
    return NULL;
}
void* Consumer(void* args){
    sem_wait(&producer);
    sem_wait(&buffermutex);
    //critical section of consumer thread where it deals with the value at the head of the buffer
    sem_post(&buffermutex);
    sem_post(&consumer);
    return NULL;
}
void pc_main(){
    int p,c,capacity;
    cout << "Enter the number of producer threads: \n";
    cin >> p;
    cout << "Enter the number of consumer threads: \n";
    cin >> c;
    cout << "Enter the size of buffer: \n";
    cin >> capacity;
    sem_init(&consumer, 0, capacity);
    sem_init(&producer, 0, 0);
    sem_init(&buffermutex, 0, 1);
}

