#include"mvt.hpp"



void Insert_ff(node *&head, int &total_free_space){
    
    int flag=0;
    node *newnode, *temp;
    proc p;
    cout << BOLDGREEN << "\n\nEnter the process id: " << BOLDWHITE;
    cin >> p.id ;
    cout << BOLDGREEN << "Enter the process size: " << BOLDWHITE;
    cin >> p.size;
    
    temp = head;

    do{
        if((temp->flag == 0) && (temp->size > p.size)){
            
            newnode = new node();
            newnode->size = p.size;
            newnode->flag=1;
            newnode->id = p.id; 

            temp->size = temp->size - p.size;
            if(temp->prev != NULL){
                temp->prev->next = newnode;
                newnode->prev = temp->prev;
                newnode->next = temp;
                temp->prev = newnode;
            }else{
                newnode->prev = NULL;
                head = newnode;
                head->next = temp;
                temp->prev = head;
            }
            flag=1;
            total_free_space -= p.size;
            break;
        }
        else if((temp->flag == 0) && (temp->size == p.size)){
            temp->flag = 1;
            temp->id = p.id;
            flag=1;
            total_free_space -= p.size;
            break;
        }

    }while((temp = temp->next));

    fu(2);
    if(flag==1)
        cout << BOLDBLUE << "\nProcess " << BOLDWHITE << p.id << BOLDBLUE <<  " has been Allocated\n";
    else{
        if(total_free_space >= p.size)
            cout << BOLDRED << "\nProcess " << BOLDWHITE << p.id << BOLDRED << " couldn't be allocated due to external fragmentation\n";
        else
            cout << BOLDRED << "\nProcess" << BOLDWHITE << p.id << BOLDRED << " couldn't be allocated as there was no sufficient memory left\n";
    }     
}

void firstfit(){
    int choice;
    fu(3);
    cout << BOLDMAGENTA << "FIRST FIT\n\n" << RESET;
    cout << BOLDGREEN << "Enter the size of memory: " << BOLDWHITE; 
    node *head;
    int total_free_space;
    int total_size;
    cin >> total_size;
    cout << "\n\n";
    total_free_space = total_size;
    node* temp = new node();
    temp->size = total_size;
    temp->flag = 0;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    while(true){
        cout << BOLDGREEN << "Choose the operation shown below.\n\n" << BOLDWHITE;
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Display\n";
        cout << "0. Exit\n\n";

        cout << BOLDGREEN << "Your Choice: " << BOLDWHITE;
        cin >> choice;

        switch(choice){
            case 1:
                //Insert
                Insert_ff(head, total_free_space);
                break;
            case 2:
                //Remove 
                remove(head, total_free_space);
                break;
            case 3:
                //Displa
                display(head);
            case 0:
                return;
                break;
            default:
                cout << BOLDRED << "Invalid key!\n\n"; 
                break;
        }
        fu(3); 
        cout << BOLDCYAN << "Enter any key to continue: "<< BOLDWHITE;
        getchar();
        getchar();
        fu(3);
    }
}