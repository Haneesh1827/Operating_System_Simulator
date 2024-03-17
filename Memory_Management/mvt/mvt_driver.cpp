#include"mvt.hpp"
void fu(size_t max){
    long int j=1 <<16;
    for (size_t i = 0; i < max; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
}
void display(node *head){
    fu(4);
    node *temp = head;
    int i = 1; 
    cout << BOLDBLUE << "PARTITION DISPLAY\n";

    cout<< BOLDCYAN << "\nPartition No.\tSize of Partition\tProcessID\n" << BOLDWHITE;    
    while(temp){
        
        if(temp->flag == 1)
            cout << i << "\t\t" << temp->size << "\t\t\t" << temp->id << "\n";
        else
            cout << BOLDRED << i << "\t\t" << temp->size << "\t\t\t" << "NA\n" << BOLDWHITE;
        i++;
        temp = temp->next;
    }
}
void remove(node *head, int &total_free_space){
    
    int flag=0;
    node *temp = NULL, *dealloc = NULL;
    proc p;
    cout << BOLDGREEN << "\nEnter the Process ID of the process to be removed: " << BOLDWHITE;
    cin >> p.id;
    temp = head;

    while(temp){
        if((temp->flag == 1) && (temp->id == p.id)){
            flag = 1;
            dealloc = temp;
            break;
        }
    
        temp = temp->next;
    }
    total_free_space += dealloc->size;
    temp = NULL;

    if(flag==1){
        dealloc->flag = 0;
        dealloc->id = -1;
        if(dealloc->next != NULL){
            if(dealloc->next->flag == 0){
                temp = dealloc->next;
                dealloc->size += temp->size;
                dealloc->next = temp->next;
                delete temp;
            }
        }
        if(dealloc->prev != NULL){
            if(dealloc->prev->flag == 0){
                temp = dealloc->prev;
                dealloc->size += temp->size;
                dealloc->prev = temp->prev;
                delete temp;
            }
        }
        
        cout << BOLDBLUE << "\nProcess " << BOLDWHITE << p.id << BOLDBLUE << " is deallocated\n" << RESET;
    }
    else
        cout<< BOLDRED "\nProcess " << BOLDWHITE << p.id << BOLDRED << " does not exist in memory.\n" << RESET;
    
    
}
int mvt_input_choice(){
  
    int choice;
    cout << BOLDGREEN << "Choose Algorithm to simulate\n\n" << BOLDWHITE;
	cout << "1. Bestfit\n";
	cout << "2. Worstfit\n";	
    cout << "3. Firstfit\n";
	cout << "0. Main menu \n\n";

	cout << BOLDGREEN << "Your choice: " << BOLDWHITE;
	cin >> choice;
	return choice;
}
void Continous_mem_alloc(){
    fu(3);
    cout << BOLDMAGENTA << "CONTINOUS MEMORY ALLOCATION" << RESET;
    fu(3);
    while(true){
        int choice = mvt_input_choice();
        switch (choice){
            case 0: 
                return;
			case 1:
				//Page Replacement
                bestfit();
				break;
			case 2:
                // Continous Memory Allocation 
                worstfit();
				break;
            case 3:
                // firstfit
                firstfit();
                break;
            default:
                cout << BOLDRED << "Invalid key!\n\n"; 
                break; 
		} 
    }
    
}

