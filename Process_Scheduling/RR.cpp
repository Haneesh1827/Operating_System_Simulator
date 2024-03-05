
#include"RR.hpp"




void round_robin(vector<process> &proc_list){

    cout << "round_robin \n";
    
    int i = 0, n = proc_list.size();
   
    while(i<n){
        
        proc_list[i].remaining_bur_time = proc_list[i].bur_time;
        i++;
    }
    int x;
    cout << "\nEnter the slice time: ";
    cin >> x;

    sort(proc_list.begin(), proc_list.end(), compare_atime);

    queue<process*> que;
    process *proc_en, *proc_de = NULL;
    int curr_time = 0, completed = 0, ptr = 0,y;

    while(ptr < n){
        proc_en = &proc_list[ptr];
        if(proc_en->arr_time > curr_time)
            break;
        que.push(proc_en);
        ptr++;
    }

    while(completed != n){
        while(ptr<n){
            proc_en = &proc_list[ptr];
            if(proc_en->arr_time > curr_time)
                break;
            que.push(proc_en);
            ptr++;
        }

        if(proc_de != NULL)
            que.push(proc_de);
            
        if(que.empty()){
            curr_time = proc_list[ptr].arr_time;
            continue;
        }
        
        proc_de = que.front();
        que.pop();

        if(proc_de->bur_time == proc_de->remaining_bur_time)
            proc_de->res_time = curr_time;

        int temp;
        
        if(proc_de-> bur_time > 0){
            temp = proc_de->remaining_bur_time;
            proc_de->remaining_bur_time -= min(x,temp);
            curr_time += min(x,temp); 
        }
        if(proc_de->remaining_bur_time == 0){
            completed++;
            proc_de->com_time = curr_time ;
            proc_de->turn_time = proc_de->com_time - proc_de->arr_time;
            proc_de->wait_time = proc_de->turn_time - proc_de->bur_time;
            proc_de = NULL;
        }
        
    } 

    display_sched(proc_list);
    
  
}