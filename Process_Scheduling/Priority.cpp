
#include"Priority.hpp"


bool ComparePriority_priority::operator()(const process* a, const process* b){
    // Higher priority goes first
    return a->priority > b->priority;
}


void priority(vector<process> &proc_list){
    
    cout << "Priority Preeemptive version\n";
   
    int i = 0, n = proc_list.size();
    
    
    cout << "\nNow, Enter the arrival time and burst time for the " << n << " processes.\n";
    while(i<n){
        cout << "Priority (0 is highest priority): ";
        cin >> proc_list[i].priority;        
        i++;
    }

    sort(proc_list.begin(), proc_list.end(), compare_atime);

    priority_queue<process*, vector<process*>, ComparePriority_priority> pq;
    int curr_time = 0, completed = 0, ptr = 0, x;
    process* proc_en, *proc_de;

    while(completed != n){
        // add processes that have arrived at time 'curr_time' or before curr_time into the priority queue.
        while(ptr < n){
            proc_en = &proc_list[ptr];
            if(proc_en->arr_time > curr_time)
                break;
            pq.push(proc_en);
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

        
        proc_de = pq.top();
        pq.pop();
        if(proc_de->remaining_bur_time == proc_de->bur_time){
            proc_de->res_time = curr_time - proc_de->arr_time;
        }
        int temp;
        if(proc_de->bur_time > 0){
            if(x != -1){
                temp = proc_de->remaining_bur_time;
                proc_de->remaining_bur_time-= min(x, proc_de->remaining_bur_time);                 
                curr_time += min(x,temp);
            }
            else{
                temp = proc_de->remaining_bur_time;
                proc_de->remaining_bur_time = 0;
                curr_time += temp;
            }
        }
        if(proc_de->remaining_bur_time == 0){
            completed++;
            proc_de->com_time = curr_time ;
            proc_de->turn_time = proc_de->com_time - proc_de->arr_time;
            proc_de->wait_time = proc_de->turn_time - proc_de->bur_time;
        }
        else{
            pq.push(proc_de);
        }
    }

    display_sched(proc_list);
    
}
