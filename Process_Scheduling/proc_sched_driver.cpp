#include"proc_sched_driver.hpp"




vector<process> take_input(){
	fun(4);
	cout << BOLDGREEN << "Enter the number of processes you want for the simulation of algorithm: " << BOLDWHITE;
    int n;
    cin >> n;
	//if zero do something
	// code here
    vector<process> proc_list(n);
    int i = 0;
    cout << BOLDGREEN <<"\nEnter the arrival time and burst time for the "<< BOLDWHITE << n << BOLDGREEN << " processes.\n" ;
    while(i<n){
        proc_list[i].num = i + 1;
        cout << BOLDGREEN <<"\n\nPROCESS " << BOLDWHITE <<i + 1 << "\n\n";
        cout << BOLDGREEN<<"Arrival time: " << BOLDWHITE;
        cin >> proc_list[i].arr_time;
        cout << BOLDGREEN <<"Burst time: " << BOLDWHITE;
        cin >> proc_list[i].bur_time;
        i++;
    }
	cout << RESET << "\n";
	return proc_list;
}
int policy_choice(){
	long int j=1 <<16;
    for (size_t i = 0; i < 5; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
	int choice;
	cout << BOLDGREEN << "Choose Algorithm to simulate" << BOLDWHITE << "\n\n";
	cout << "1. First Come First Serve [FCFS]\n";
	cout << "2. Shortest Job First [SJF]\n";
	cout << "3. Round Robin [RR]\n";
	cout << "4. Longest Job First [LJF]\n";
	cout << "5. Shortest Remaining Time First [SRTF]\n";
	cout << "6. Longest Remaining Time First [LRTF]\n";
	cout << "7. Highest Response Ratio Next [HRRN]\n";
	cout << "8. Priority Non-preemptive [Pri_non]\n";
	cout << "9. Priority Preemptive [Pri_p]\n";
	cout << "0. Main menu \n\n";

	cout << BOLDGREEN <<  "Your choice : " << BOLDWHITE;
	cin >> choice;
	cout << RESET;
	return choice;
}
int post_policy_choice(){
	
    
	int choice;
	cout << BOLDGREEN <<"\nChoose among the following options and enter the corresponding number\n\n" << BOLDWHITE;
	cout << "1. To go to the main menu\n";
	cout << "2. To continue with the same set of processes enter before\n";
	cout << "3. To enter new set of processes\n\n";
	cout << BOLDGREEN <<"Your choice: " << BOLDWHITE;
	cin >> choice;
	cout << RESET; 
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
					sjf(proc_list);
					break;
				case 3:
					round_robin(proc_list);
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
				case 0:
					return;
				default:
					cout << BOLDRED << "Invalid key!\n\n"; 
					return;
			}
			long int j=1 <<16;
    		for (size_t i = 0; i < 5; i++){
        		usleep(j); // move faster and faster,
        		j = (int)(j * 0.9); // so sleep less each time
        		cout << endl;
    		}
			cout << BOLDGREEN <<"Enter a key to continue: \n" << BOLDWHITE;
			getchar();
			getchar();
			choice = post_policy_choice();
			switch (choice)
			{
			case 1://mainmenu
				return;
			case 2:
				break;//same values
			case 3://oldvalues
				flag = 0;
				break;
			default:
				cout << BOLDRED << "Invalid key!\n\n"; 
                return;
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