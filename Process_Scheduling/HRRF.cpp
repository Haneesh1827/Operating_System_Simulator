#include<iostream>
#include<vector>
#include"HRRF.hpp"
using namespace std;



double Calculate_res_ratio(process &P, int curr_time){
    return (double)(curr_time - P.arr_time + P.bur_time)/P.bur_time;
}

void hrrf(vector<process> &proc_list){
   
    cout << "HRRF what the fuck \n";
   
    int i, n = proc_list.size();

    sort(proc_list.begin(), proc_list.end(), compare_atime);
    
    int completed =0, curr_time = proc_list[0].arr_time, idx;
    double res_ratio, maxi = 0;

    while(completed != n){
        idx = -1;
        maxi = 0; 
        for(i = 0; proc_list[i].arr_time <= curr_time && i < n; i++){
            if(proc_list[i].isCompleted == 1){
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
            proc_list[idx].isCompleted = 1;
        }
    }
    display_sched(proc_list); 
}