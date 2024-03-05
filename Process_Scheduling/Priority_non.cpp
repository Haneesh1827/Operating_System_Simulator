
#include"Priority_non.hpp"




bool ComparePriority::operator()(const process* a, const process* b){
    // Higher priority goes first
    return a->priority > b->priority;
}



void priority_non(vector<process> &proc_list){
    
    cout << "Priority Non-Preemptive \n";
   
    int i = 0, n = proc_list.size() ;
    
    cout << "\nNow, Enter the priority for the " << n << "processes.\n";
    while(i<n){
        
        cout << "Enter priority(0 is highest priority): ";
        cin >> proc_list[i].priority;
        i++;
        
    }
    
    sort(proc_list.begin(), proc_list.end(), compare_atime);

    priority_queue<process*, vector<process*>, ComparePriority> pq;
    int curr_time = 0, completed = 0, ptr = 0;
    process* proc_en, *proc_de;
   
    while(completed != n){
        // add processes into priority queue, priority is high burst time in this case
        while(ptr<n){
            proc_en = &proc_list[ptr];
            if(proc_en->arr_time > curr_time)
                break;
            pq.push(proc_en);
            ptr++;
        } 
        if(pq.empty()){
            curr_time = proc_list[ptr].arr_time;
            continue;
        }
        proc_de = pq.top();
        pq.pop();
        proc_de->res_time = curr_time;
        curr_time += proc_de->bur_time;
        completed++;
        proc_de->com_time = curr_time;
        proc_de->turn_time = proc_de->com_time - proc_de->arr_time;
        proc_de->wait_time = proc_de->turn_time - proc_de->bur_time;
    }

    display_sched(proc_list);
    
}
