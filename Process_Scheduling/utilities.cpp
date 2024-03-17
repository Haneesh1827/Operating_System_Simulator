#include "utilities.hpp"


void fun(size_t max){
    long int j=1 <<16;
    for (size_t i = 0; i < max; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
}

bool compare_atime(process P, process Q) //to sort according to arrival time
{
    if(P.arr_time == Q.arr_time)
        return P.bur_time < Q.bur_time;
    return (P.arr_time < Q.arr_time);
} 

void display_avg(vector<process> proc_list){
    int n = proc_list.size();
    double avg_turnaround_t, avg_waiting_t, avg_response_t;
    double total_turnaroun_t = 0, total_waiting_t = 0, total_response_t = 0;
    for(int i = 0; i < n; i++){
        total_turnaroun_t += proc_list[i].turn_time;
        total_waiting_t += proc_list[i].wait_time;
        total_response_t += proc_list[i].res_time;
    }
    avg_turnaround_t = total_turnaroun_t / n;
    avg_waiting_t = total_waiting_t / n;
    avg_response_t = total_response_t / n;
    cout << BOLDCYAN << "\nAverage Turnaround Time: " << BOLDWHITE << avg_turnaround_t << "\n\n";
    cout << BOLDCYAN << "Average Waiting Time: " << BOLDWHITE << avg_waiting_t << "\n\n";  
    cout << BOLDCYAN << "Average Response Time: " << BOLDWHITE << avg_response_t; 
}
void display_sched(std::vector<process> &proc_list){
    int n = proc_list.size();
    
    std::cout<< BOLDCYAN << "\n\nProcess No.\tArrival Time\tBurst Time\tCompletion Time\t\tTurn-around Time\tWaiting Time\tResponse Time\n" << RESET;
    for(int i = 0; i < n; i++){
        std::cout<<proc_list[i].num<<"\t\t";
        std::cout<<proc_list[i].arr_time<<"\t\t";
        std::cout<<proc_list[i].bur_time<<"\t\t";
        std::cout<<proc_list[i].com_time<<"\t\t\t";
        std::cout<<proc_list[i].turn_time<<"\t\t\t";
        std::cout<<proc_list[i].wait_time<<"\t\t";
        std::cout<<proc_list[i].res_time<<"\n";
    }
}