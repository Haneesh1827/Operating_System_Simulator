
#include"disk.hpp"

void take_input(Arg &arg){
	cout << BOLDGREEN <<"\n\nEnter the number of disk requests: " << BOLDWHITE;
    int n;
	cin >> n;
	//if zero do something
	// code here
	arg.seekreq.resize(n);
	cout << BOLDGREEN << "\nEnter the length of the disk: " << BOLDWHITE;
	cin >> arg.disk_size;
	cout << BOLDGREEN << "\nEnter the starting location: " << BOLDWHITE;
	cin >> arg.startseekloc;
    int i = 0;
    cout << BOLDGREEN << "\nEnter the locations of the " << n << " disk requests.\n\n" << BOLDWHITE;
	i = 0;
    while(i<n){
		cin >> arg.seekreq[i];
        i++;
    }
	cout << RESET;
	
}
int dpolicy_choice(){
	int choice;
	cout << BOLDGREEN << "\nChoose Algorithm to simulate" << RESET << BOLDWHITE <<  "\n\n";
	cout << " 1. FCFS\n";
	cout << " 2. SCAN\n";
	cout << " 3. CSCAN\n";
	cout << " 4. LOOK\n";
	cout << " 5. CLOOK\n";
	cout << " 9. Main menu \n\n";

	cout << BOLDGREEN << "Your choice : " << BOLDWHITE;
	cin >> choice;
	cout << RESET;
	return choice;																																																								
}
int dpost_policy_choice(){
	long int j=1 <<16;
    for (size_t i = 0; i < 5; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
    
	int choice;
	cout << BOLDGREEN << "Choose among the following options and enter the corresponding number\n\n" << BOLDWHITE;
	cout << "1. To go to the main menu\n";
	cout << "2. To continue with the same set of disk seeks entered before\n";
	cout << "3. To enter new set of processes\n\n";
	cout << BOLDGREEN << "Your choice: " << BOLDWHITE;
	cin >> choice;
	cout << RESET;
	return choice;
}
void requests_entered(Arg arg){
	cout << BOLDCYAN << "The order of disk seek requests as entered: " << BOLDWHITE;
	int i, n = arg.seekreq.size();
	for(i = 0; i < n; i++)
		cout << arg.seekreq[i] << " ";
	cout << "\n\n";	
}
void disk_main(){
   int flag;
	while(true){
		Arg arg;	
		take_input(arg);	
		flag = 1;
		while(true){
        	int choice = dpolicy_choice();
			switch (choice){
				case 1:
					Fcfs_main(arg);
					break;
				case 2:
					//SCAN
					Scan_main(arg);
					break;
				case 3:
					//CSCAN
					Cscan_main(arg);
					break;
				case 4:
					//LOOK
					Look_main(arg);
					break;
				case 5:
					//CLOOK
					Clook_main(arg);
					break;
				case 9:
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
			cout << BOLDGREEN << "Enter a key to continue: \n" << BOLDWHITE;
			getchar();
			getchar();
			cout << RESET;
			choice = dpost_policy_choice();
			switch (choice)
			{
			case 1://mainmenu
				return;
			case 2://old values
				break;
			case 3://new values
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
