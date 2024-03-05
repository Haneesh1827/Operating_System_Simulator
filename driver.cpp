#include"animations.hpp"
#include"Process_Synchronization/proc_sync_driver.hpp"
#include"Process_Scheduling/proc_sched_driver.hpp"
#include"Disk_Scheduling/disk_driver.hpp"
#include"Memory_Management/memory_driver.hpp"
#include<iostream>
#include<vector>

using std::cout;
using std::vector;

int main(){
    int choice;
    main_animation();
	cout << "Print any key to continue : ";
	getchar();
    while (true)
	{
		// Print the menu
		// defined in animations
		print_main_menu();

		//user choice
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			paging_animation();

			break;
		case 2:
			dead_safe_animation();
			break;
		case 3:
			process_sched_animation();
			proc_sched_main();
			break;
		case 4:
			mem_animations();
			break;
		case 5:
			sync_animations();
			break;
		case 6:
			disk_animations();
			break;
		case 9:
			return 0;
		default:
			cout << "Wrong input" << endl;
		}
	}
	return 0;
}
