#include<iostream>
#include"utilities.hpp"
#include"RR.hpp"
using namespace std;



void round_robin(vector<process> &proc_list){
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
        j++;
    }
    int x;
    cout << "\nEnter the slice time: ";
    cin >> x;

    sort(proc_list.begin(), proc_list.end(), srtf_comp_atime);

    queue<Process*> que;
    Process *proc_en, *proc_de = NULL;
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