#include<iostream>
#include<vector>
#include"utilities.hpp"
#include"LJF.hpp"
using namespace std;


bool ComparePriority_ljf::operator()(const process* a, const process* b) {
    // Higher priority goes first
    return a->bur_time < b->bur_time;
}



void ljf(vector<process> &proc_list){
    /*cout << "This is the demo for Shortest Remaining Time First scheduling algorithm \n";
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
       
        j++;
        
    }
    
    sort(proc_list.begin(), proc_list.end(), srtf_comp_atime);

    priority_queue<Process*, vector<Process*>, ComparePriority> pq;
    int curr_time = 0, completed = 0, ptr = 0;
    Process* proc_en, *proc_de;
   
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
