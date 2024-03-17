
#include"proc_sync_driver.hpp"

void func(size_t max){
    long int j=1 <<16;
    for (size_t i = 0; i < max; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
}
int post_sync_choice(){
    long int j=1 <<16;
    for (size_t i = 0; i < 5; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
    
	int choice;
	cout << BOLDGREEN << "Choose among the following options and enter the corresponding number\n\n" << BOLDWHITE;
	cout << "0. To go to the main menu\n";
	cout << "1. To continue with the other process synchronization problems\n";
	
	cout << BOLDGREEN << "\nYour choice: " << BOLDWHITE;
	cin >> choice; 
    cout << RESET;
	return choice;
}
int input_choice(){
    long int j=1 <<16;
    for (size_t i = 0; i < 5; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
	int choice;
	cout << BOLDGREEN << "Choose Algorithm to simulate" << "\n\n" << BOLDWHITE;
	cout << "1. Producer Consumer\n";
	cout << "2. Reader Writer\n";
	cout << "3. Dining Philsophers\n";
	cout << "4. BarberShop\n";
    cout << "5. Deadlock Dectection\n";	
	cout << "0. Main menu \n\n";

	cout << BOLDGREEN <<"Your choice : " << BOLDWHITE;
	cin >> choice;
    cout << RESET;
	return choice;
}
void proc_sync_main(){
    while(true){
        int choice = input_choice();
        switch (choice){
            case 0: 
                return;
			case 1:
				// Producer Consumer
                Producer_consumer();
				break;
			case 2:
                // Reader Writer
                Reader_writer();
				break;
			case 3:
                // Dining Philosophers
                Dining_phil();
				break;
			case 4:
                //Barbershop
                Barber_shop();
            	break;
            case 5:
                //Deadlock Detection
                bankers_main();
                break;
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
        choice = post_sync_choice();
        if(choice == 0)// main menu
            break;
        if(choice !=1){ //default case
            cout << BOLDRED << "Invalid key!\n\n"; 
        }
    } 
}