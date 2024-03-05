#include<iostream>
#include"utilities.hpp"
#include"SRTF.hpp"
#include<vector>

bool  ComparePriority_SRTF::operator()(const process* a, const process* b) {
    // Higher priority goes first
    return a->remaining_bur_time > b->remaining_bur_time;
}



void srtf(std::vector<process>& proc_list){
    /*
    
    cout << "This is the demo for Shortest Remaining Time First scheduling algorithm \n";
    
    int i = 0;
    int n = proc_list.size();
    while(i<n){
        proc_list[i].remaining_bur_time = proc_list[i].bur_time;
        i++;    
    }

    sort(proc_list.begin(), proc_list.end(), srtf_comp_atime);
 
    priority_queue<Process*, vector<Process*>, ComparePriority> pq;
    int curr_time = 0, completed = 0, ptr = 0, x;
    Process* proc;

    while(completed != n){
        // add processes that have arrived at time 'curr_time' or before curr_time into the priority queue.
        while(ptr < n){
            proc = &proc_list[ptr];
            if(proc->arr_time > curr_time)
                break;
            pq.push(proc);
            ptr++;
        }
        if(ptr<n){
            x = proc_list[ptr].arr_time - curr_time;
        }
        else if(ptr == n){
            x = -1;
        }
        //if pq is empty, then just do only curr_time ++ and continue onto the next loop; 
        if(pq.empty() == true){
            curr_time+= x;
            continue;
        }

        
        Process* temp = pq.top();
        pq.pop();
        if(temp->remaining_bur_time == temp->bur_time){
            temp->res_time = curr_time - temp->arr_time;
        }
        int tmp;
        if(temp->bur_time > 0){
            if(x != -1){
                tmp = temp->remaining_bur_time;
                temp->remaining_bur_time-= min(x, temp->remaining_bur_time);                 
                curr_time += min(x,tmp);
            }
            else{
                tmp= temp->remaining_bur_time;
                temp->remaining_bur_time = 0;
                curr_time += tmp;
            }
        }
        if(temp->remaining_bur_time == 0){
            completed++;
            temp->com_time = curr_time ;
            temp->turn_time = temp->com_time - temp->arr_time;
            temp->wait_time = temp->turn_time - temp->bur_time;
        }
        else{
            pq.push(temp);
        }
    }
    display_sched(proc_list);
   */
}
