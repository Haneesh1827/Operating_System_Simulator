
#include"LRTF.hpp"




class ComparePriority_LRTF {
public:
    bool operator()(const process* a, const process* b) {
        if(a->priority == b->priority)    
            return a->arr_time > b->arr_time;// Higher priority goes first
        return a->priority < b->priority;
    }
};



void lrtf(vector<process>& proc_list){
    
    cout << "LRTF \n";
    
    int i = 0, n = proc_list.size();
    
    while(i<n){
        proc_list[i].remaining_bur_time = proc_list[i].bur_time;
        i++;
        
    }
    
    sort(proc_list.begin(), proc_list.end(), compare_atime);

    priority_queue<process*, vector<process*>, ComparePriority_LRTF> pq;
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
            x = INT_MAX;
        }
        //if pq is empty, then just do only curr_time ++ and continue onto the next loop; 
        if(pq.empty() == true){
            curr_time += x;
            continue;
        }

        
        proc_de = pq.top();
        pq.pop();
        process* temp = pq.top();
        if(proc_de->priority == temp->priority)
            x = 1;
        else
            x  = min(x, proc_de->priority - temp->priority);
        if(proc_de->priority == proc_de->bur_time){
            proc_de->res_time = curr_time - proc_de->arr_time;
        }


        int tmp;
        if(proc_de->bur_time > 0){
            if(x != INT_MAX){
                tmp = proc_de->priority;
                proc_de->priority-= min(x, proc_de->priority);                 
                curr_time += min(x,tmp);
            }
            else{
                tmp = proc_de->priority;
                proc_de->priority = 0;
                curr_time += tmp;
            }
        }

        if(proc_de->priority == 0){
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