
#include"memory_driver.hpp"
using namespace std;
int minput_choice(){
    long int j=1 <<16;
    for (size_t i = 0; i < 5; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
	int choice;
	cout << BOLDGREEN << "Choose Algorithm to simulate" << "\n\n" << BOLDWHITE;
	cout << "1. Page Replacement\n";
	cout << "2. Continous Memory Allocation\n";	
	cout << "0. Main menu \n\n";

	cout << BOLDGREEN << "Your choice: "<<BOLDWHITE;
	cin >> choice;
	return choice;
}
void memory_main(){
    while(true){
        int choice = minput_choice();
        switch (choice){
            case 0: 
                break;
			case 1:
				//Page Replacement
                page_replacement();
				break;
			case 2:
                // Continous Memory Allocation 
                Continous_mem_alloc();
				break;
            default: 
                cout << BOLDRED <<"Invalid key!";
                break;
		}
        if(choice == 0)
            break;
        
    }
}