#include"animations.hpp"
#include"Process_Synchronization/proc_sync_driver.hpp"
#include"Process_Scheduling/proc_sched_driver.hpp"
#include"Disk_Scheduling/disk.hpp"
#include"Memory_Management/memory_driver.hpp"
#include<iostream>
#include<vector>

using namespace std;
int main(){
    int choice;
    main_animation();
	cout << BOLDGREEN <<"Print any key to continue : " << BOLDWHITE;
	getchar();
	cout << RESET;
    while (true){
		// Print the menu
		// defined in animations
		print_main_menu();

		//user choice
		cout << WHITE;
		cin >> choice;
		cout << RESET;	
		switch (choice){
			case 1:
				process_sched_animation();
				proc_sched_main();
				break;
			case 2:
				mem_animations();
				memory_main();
				break;
			case 3:
				sync_animations();
				proc_sync_main();
				break;
			case 4:
				disk_animations();
				disk_main();
				break;
			case 9:
				return 0;
			default:
				cout << "Wrong input" << endl;
		}
	}
	return 0;
}
