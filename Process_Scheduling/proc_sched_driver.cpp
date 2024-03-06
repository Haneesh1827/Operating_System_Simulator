#include<iostream>
#include"FCFS.hpp"
#include"SJF.hpp"
#include"SRTF.hpp"
#include"LJF.hpp"
#include"LRTF.hpp"
#include"Priority.hpp"
#include"Priority_non.hpp"
#include"RR.hpp"
#include"HRRF.hpp"
#include <unistd.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define UN "\e[4m"
using namespace std;

vector<process> take_input(){
	long int j=1 <<16;
    for (size_t i = 0; i < 10; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
	cout << BOLDGREEN << "Enter the number of processes you want for the simulation of algorithm: ";
    int n;
    cin >> n;
    vector<process> proc_list(n);
    int i = 0;
    cout << "Enter the arrival time and burst time for the " << n << " processes.\n";
    while(i<n){
        proc_list[i].num = i + 1;
        cout << "\n PROCESS " << i + 1 << "\n";
        cout << " Arrival time: ";
        cin >> proc_list[i].arr_time;
        cout << " Burst time: ";
        cin >> proc_list[i].bur_time;
        i++;
    }
	cout << RESET << "\n";
	return proc_list;
}
int policy_choice(){
	long int j=1 <<16;
    for (size_t i = 0; i < 10; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
	int choice;
	cout << BOLDGREEN << UN << "Choose Algorithm to simulate" << RESET << "\n\n";
	cout << " 1. First Come First Serve [FCFS]\n";
	cout << " 2. Shortest Job First [SJF]\n";
	cout << " 3. Round Robin [RR]\n";
	cout << " 4. Longest Job First [LJF]\n";
	cout << " 5. Shortest Remaining Time First [SRTF]\n";
	cout << " 6. Longest Remaining Time First [LRTF]\n";
	cout << " 7. Highest Response Ratio Next [HRRN]\n";
	cout << " 8. Priority Non-preemptive [Pri_non]\n";
	cout << " 9. Priority Preemptive [Pri_p]\n";
	cout << " 10. Main menu \n\n";

	cout << BOLDGREEN <<  "Your choice : ";
	cin >> choice;
	return choice;
}
int post_policy_choice(){
	long int j=1 <<16;
    for (size_t i = 0; i < 10; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
    
	int choice;
	cout << "Choose among the following options and enter the corresponding number";
	cout << " 1. To go to the main menu\n";
	cout << " 2. To continue with the same set of processes enter before\n";
	cout << " 3. To enter new set of processes\n";
	cout << "Your choice: ";
	cin >> choice; 
	return choice;
}
void proc_sched_main(){
	int flag;
	while(true){
		vector<process> proc_list = take_input();	
		flag = 1;
		while(true){
        	int choice = policy_choice();
			switch (choice){
				case 1:
					fcfs(proc_list);

					break;
				case 2:
					cout <<" hello\n";
					sjf(proc_list);
					break;
				case 3:
					cout << "hello";
					round_robin(proc_list);
					cout << "hello\n";
					break;
				case 4:
					ljf(proc_list);
					break;
				case 5:
					srtf(proc_list);
					break;
				case 6:
					lrtf(proc_list);
					break;
				case 7:
					hrrf(proc_list);
					break;
				case 8:
					priority_non(proc_list);
					break;
				case 9:
					priority(proc_list);
					break;
				case 10:
					return;
			}
			cout << "Enter a key to continue: \n";
			getchar();
			getchar();
			choice = post_policy_choice();
			switch (choice)
			{
			case 1:
				return;
				break;
			case 2:
				break;
			case 3:
				flag = 0;
				break;
			default:
				break;
			}
			if(flag == 0)
				break;
		}		
	}
}
/*
int main(){
	proc_sched_main();
}
*/