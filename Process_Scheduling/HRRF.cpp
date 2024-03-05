#include<iostream>
#include<vector>
#include"HRRF.hpp"
using namespace std;



double Calculate_res_ratio(process &P, int curr_time){
    return (double)(curr_time - P.arr_time + P.bur_time)/P.bur_time;
}

void hrrf(vector<process> &proc_list){
    /*
    cout << "This is the demo for Shortest Remaining Time First scheduling algorithm \n";
    cout << "Enter the number of processes you want for the simulation of algorithm: ";
    int n;
    cin >> n;
    vector<Process> proc_list(n);
    int i = 0;
    cout << "\nNow, Enter the arrival time and burst time for the " << n << " processes.\n";
    while(i<n){
        proc_list[i].num = i + 1;
        cout << "\nPROCESS__" << i + 1 << "\n\n";
        cout << "Arrival time: ";
        cin >> proc_list[i].arr_time;
        cout << "Burst time: ";
        cin >> proc_list[i].bur_time;
        i++;
    }

    sort(proc_list.begin(), proc_list.end(), srtf_comp_atime);
    
    int completed =0, curr_time = proc_list[0].arr_time, idx;
    double res_ratio, maxi = 0;

    while(completed != n){
        idx = -1;
        maxi = 0; 
        for(i = 0; proc_list[i].arr_time <= curr_time && i < n; i++){
            if(proc_list[i].iscompleted == 1){
                continue;
            }
            res_ratio = Calculate_res_ratio(proc_list[i], curr_time);
            if(maxi < res_ratio){
                idx = i;
                maxi = res_ratio;
            }
            else if(maxi == res_ratio){
                if(proc_list[idx].bur_time > proc_list[i].bur_time){
                    idx = i;
                }
            }
        }
        if(idx == -1){
            curr_time = proc_list[i].arr_time;
        }
        else{
            proc_list[idx].res_time = curr_time;
            curr_time += proc_list[idx].bur_time;
            completed++;
            proc_list[idx].com_time = curr_time;
            proc_list[idx].turn_time = proc_list[idx].com_time - proc_list[idx].arr_time;
            proc_list[idx].wait_time = proc_list[idx].turn_time - proc_list[idx].bur_time;
            proc_list[idx].iscompleted = 1;
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