#include<iostream>
#include"utilities.hpp"
#include"Priority.hpp"
#include<vector>
using namespace std;

bool ComparePriority_priority::operator()(const process* a, const process* b){
    // Higher priority goes first
    return a->priority > b->priority;
}


void priority(vector<process> &proc_list){
    /*
    cout << "This is the demo for Shortest Remaining Time First scheduling algorithm \n";
    cout << "Enter the number of processes you want for the simulation of algorithm: ";
    int n;
    cin >> n;
    vector<Process> proc_list(n);
    int j = 0;
    cout << "\nNow, Enter the arrival time and burst time for the " << n << " processes.\n";
    while(j<n){
        proc_list[j].num = j + 1;
        cout << "\nPROCESS__" << j + 1 << "\n\n";
        cout << "Arrival time: ";
        cin >> proc_list[j].arr_time;
        cout << "Burst time: ";
        cin >> proc_list[j].bur_time;
        proc_list[j].remaining_bur_time = proc_list[j].bur_time;
        cout << "Priority (0 is highest priority): ";
        cin >> proc_list[j].priority;        
        j++;
    }

    sort(proc_list.begin(), proc_list.end(), srtf_comp_atime);

    priority_queue<Process*, vector<Process*>, ComparePriority> pq;
    int curr_time = 0, completed = 0, ptr = 0, x;
    Process* proc_en, *proc_de;

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

    //Displaying the times in tabular form
    cout<<"\n\nP.no.\tAT\tBT\tCT\tTAT\tWT\tRT\n"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<proc_list[i].num<<"\t";
        cout<<proc_list[i].arr_time<<"\t";
        cout<<proc_list[i].bur_time<<"\t";
        cout<<proc_list[i].com_time<<"\t";
        cout<<proc_list[i].turn_time<<"\t";
        cout<<proc_list[i].wait_time<<"\t";
        cout<<proc_list[i].res_time<<"\t"<<"\n";
    }
    */
}
