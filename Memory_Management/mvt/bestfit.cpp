#include"mvt.hpp"



void Insert_bf(node *&head, int &total_free_space){
    int flag = 0, min;
 
    node *newnode, *temp, *minNode = NULL;
    proc p;
    cout << BOLDGREEN << "\n\nEnter the process id: " << BOLDWHITE;
    cin >> p.id ;
    cout << BOLDGREEN << "Enter the process size: " << BOLDWHITE;
    cin >> p.size;

    temp = head;
    min = total_free_space + 1;

    while(temp){
        if(temp->flag == 0 && temp->size >= p.size){
            if(temp->size < min){
                minNode = temp;
                min = temp->size;
            }
        }
        temp = temp->next;
    
    }

    if(minNode != NULL){
        if(minNode->size == p.size){
            minNode->flag = 1;
            minNode->id = p.id;  
        }
        else{
            newnode = new node();
            newnode->size = p.size;
            newnode->flag=1;
            newnode->id = p.id; 

            minNode->size -= p.size;
            if(minNode->prev != NULL){
                minNode->prev->next = newnode;
                newnode->prev = minNode->prev;
                newnode->next = minNode;
                minNode->prev = newnode;                
            }

            else{
                newnode->prev = NULL;
                head = newnode;
                head->next = minNode;
                minNode->prev = head; 
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


void bestfit(){
    int choice, total_size, total_free_space;
    node *head;
    fu(3);
    cout << BOLDMAGENTA << "BEST FIT\n\n" << RESET;
    cout << BOLDGREEN << "Enter the size of memory: " << BOLDWHITE;
    
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
                Insert_bf(head, total_free_space);
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