
#include"Priority.hpp"


bool ComparePriority_priority::operator()(const process* a, const process* b){
    // Higher priority goes first
    if(a->priority == b->priority)
        return a->bur_time > b->bur_time;
    return a->priority > b->priority;
}


void priority(vector<process> proc_list){
    fun(6);
    cout << BOLDMAGENTA <<"PRIORITY FIRST (Preeemptive version)\n" << RESET;
   
    int i = 0, n = proc_list.size(); 
    
    
    cout << BOLDGREEN << "\nEnter the priority for the " << BOLDWHITE << n << BOLDGREEN << " processes.\n";
    while(i<n){
        cout << BOLDGREEN << "Priority (0 is highest priority): " << BOLDWHITE;
        cin >> proc_list[i].priority;
        proc_list[i].remaining_bur_time = proc_list[i].bur_time;        
        i++;
    }

    sort(proc_list.begin(), proc_list.end(), compare_atime); // sort by arrival time, if equal then bu burst time


    priority_queue<process*, vector<process*>, ComparePriority_priority> pq;  //priority queue used for dequeueing the right process based on priority
    int curr_time = 0, completed = 0, x;  
    process* proc_en, *proc_de; //pointer to process that is enqueued into the pq from the proc_list wrt the curr_time, pointer to the process that is dequeued from pq.
    i = 0;

    // loops till completed reaches n (after each process is completed, completed is incremented)
    while(completed != n){
        // add processes that have arrived at time 'curr_time' or before curr_time into the priority queue.
        while(i < n){
            proc_en = &proc_list[i]; //the address of the process in the proc_list is taken 
            if(proc_en->arr_time > curr_time) //loops till all the arrived process are enqueued at t = curr_time
                break;
            pq.push(proc_en);
            i++;
        }

        if(i == n)
            x = -1;
        else
            x = proc_list[i].arr_time - curr_time;

        //if pq is empty, then just do only curr_time ++ and continue onto the next loop; 
        if(pq.empty() == true){
            curr_time += x;
            continue;
        }

       
        proc_de = pq.top(); 
        pq.pop(); // dequeue the process ( ofc.. highest priority is dequeued)

        if(proc_de->remaining_bur_time == proc_de->bur_time){
            proc_de->res_time = curr_time - proc_de->arr_time; //if rem_time is equal to bur_time, fill the response time of process
        }

        if(proc_de->bur_time > 0){
            // if all of the processes are enqueued into pq, update the curr_time till the dequeued process is done (remaining_bur_time = 0)
            if(x == -1){ // x = -1 indicates all of them enqueued into pq
                curr_time += proc_de->remaining_bur_time;
                proc_de->remaining_bur_time = 0;
            }
            //if all of the processes are not yet enqueued from the proc_list, proc_de should run till a new process is enqueued into pq
            else{
                curr_time += min(x, proc_de->remaining_bur_time); 
                proc_de->remaining_bur_time-= min(x, proc_de->remaining_bur_time);                 
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
    std::cout<< BOLDCYAN << "\n\nProcess No.\tPriority\tArrival Time\tBurst Time\tCompletion Time\t\tTurn-around Time\tWaiting Time\tResponse Time\n" << RESET;
    for(int i = 0; i < n; i++){
        std::cout<<proc_list[i].num<<"\t\t";
        std::cout<<proc_list[i].priority<<"\t\t";
        std::cout<<proc_list[i].arr_time<<"\t\t";
        std::cout<<proc_list[i].bur_time<<"\t\t";
        std::cout<<proc_list[i].com_time<<"\t\t\t";
        std::cout<<proc_list[i].turn_time<<"\t\t\t";
        std::cout<<proc_list[i].wait_time<<"\t\t";
        std::cout<<proc_list[i].res_time<<"\n";
    }
    display_avg(proc_list);
    
}
