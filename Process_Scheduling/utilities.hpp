#ifndef UTILITIES

#define UTILITIES
#include<vector>
#include<algorithm>
#include<iostream>
class process{
    public:
    int num; //process number
    int arr_time; // arrival time
    int bur_time; // burst time
    int com_time; // completion time
    int res_time; // response time
    int wait_time; // wait time
    int turn_time; // turnaround time
    int priority; //priority
    int remaining_bur_time; //remaining_bur_time
    int isCompleted;
};

bool compare_atime(process P, process Q); //to sort according to arrival time
void display_sched(std::vector<process> &proc_list);


#endif