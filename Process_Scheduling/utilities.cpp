#include "utilities.hpp"



bool compare_atime(process P, process Q) //to sort according to arrival time
{
    if(P.arr_time == Q.arr_time)
        return P.num < Q.num;
    return (P.arr_time < Q.arr_time);
} 

void display_sched(std::vector<process> &proc_list){
    int n = proc_list.size();
    std::cout<<"\n\nP.no.\tAT\tBT\tCT\tTAT\tWT\tRT\n\n";
    for(int i = 0; i < n; i++){
        std::cout<<proc_list[i].num<<"\t";
        std::cout<<proc_list[i].arr_time<<"\t";
        std::cout<<proc_list[i].bur_time<<"\t";
        std::cout<<proc_list[i].com_time<<"\t";
        std::cout<<proc_list[i].turn_time<<"\t";
        std::cout<<proc_list[i].wait_time<<"\t";
        std::cout<<proc_list[i].res_time<<"\t"<<"\n";
    }
}