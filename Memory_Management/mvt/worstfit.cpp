#include"mvt.hpp"


void Insert_wf(node *&head, int &total_free_space){
    int flag = 0, max;
    
    node *newnode, *temp, *maxNode = NULL;
    proc p;
    cout << BOLDGREEN << "\n\nEnter the process id: " << BOLDWHITE;
    cin >> p.id ;
    cout << BOLDGREEN << "Enter the process size: " << BOLDWHITE;
    cin >> p.size;

    temp=head;
    max = -1;

    while(temp){
        if(temp->flag == 0 && temp->size >= p.size){
            if(temp->size > max){
                maxNode = temp;
                max = temp->size;
            }
        }
        temp = temp->next;
    }

    if(maxNode != NULL){
        if(maxNode->size == p.size){
            maxNode->flag = 1;
            maxNode->id = p.id;  
        }
        else{
            newnode = new node();
            newnode->size = p.size;
            newnode->flag = 1;
            newnode->id = p.id; 

            maxNode->size -= p.size;
            if(maxNode->prev != NULL){
                maxNode->prev->next = newnode;
                newnode->prev = maxNode->prev;
                newnode->next = maxNode;
                maxNode->prev = newnode;
            }else{
                newnode->prev = NULL;
                head = newnode;
                head->next = maxNode;
                maxNode->prev = head;
            }    
        }
        flag=1;
        total_free_space -= p.size;
    }

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


void worstfit(){
    int choice;
    fu(3);
    cout << BOLDMAGENTA << "BEST FIT\n\n" << RESET;
    cout << BOLDGREEN << "Enter the size of memory: " << BOLDWHITE;
    node* head = NULL;
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
                Insert_wf(head, total_free_space);
                break;
            case 2:
                //Remove 
                remove(head, total_free_space);
                break;
            case 3:
                //Display
                display(head);
                break;
            case 0: 
                return;
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