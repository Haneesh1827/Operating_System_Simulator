#include"deadlockdetection.hpp"
void bankers_main(){     

        func(5);
        cout << BOLDMAGENTA << "DEADLOCK DETECTION";
        int r, p, i, j;

        cout<< BOLDGREEN << "\n\nEnter the no. of processes: " << BOLDWHITE;
        cin>>p;
        cout<< BOLDGREEN << "Enter the no. of different resources present: " << BOLDWHITE;
        cin>>r;
        int resources[r], sum[r]={0};
        cout << "\n\n";
        for(i = 0; i < r; i++){
            cout<< BOLDGREEN << "Enter the total no. of instances of R"<<i+1<<": " << BOLDWHITE;
            cin>>resources[i];
        }
        cout << "\n\n";
        int order[p]; //for maintaining the sequence for running the processes
        int allocated[p][r], required[p][r], remaining[p][r];
        int available[r]; 

        cout<< BOLDGREEN << "For each process enter the no. of current allocated resources.\n";
        for(i = 0; i < p; i++){

            cout<< BOLDGREEN << "Process " << i+1 << ": " << "\n";
            for(j = 0; j < r; j++){
                cout << BOLDGREEN << "R"<< j+1 << BOLDWHITE << ": ";
                cin >> allocated[i][j];
                sum[j] += allocated[i][j];
            }
            cout << "\n";
        }
        //checking if total allocated resources exceeds the available resources
        for(i = 0; i < r; i++){
            if(sum[i] > resources[i]){
                cout << BOLDRED << "The entered no. of resources are more than the total no. of instances present, the program will terminate, try again.\n";
                return;
            }
        }
        

        cout<< BOLDGREEN << "For each process enter the number of future required resources.\n";
        for(i = 0; i < p; i++){
            cout << BOLDGREEN << "Process " << i+1 << "\n";
            for(j = 0; j < r; j++){
                cout << BOLDGREEN << "R" << j+1 << ": " << BOLDWHITE;
                cin >> required[i][j];
                if(required[i][j] > resources[j]){
                    cout << BOLDRED << "The process is requesting for more resources than available, the program will terminate, try again \n";
                    return;
                }
            }
            cout << "\n";
        }

        for(i = 0; i < r; i++){
            available[i] = resources[i] - sum[i];
        }

        for(i = 0; i < p; i++){
            for(j = 0; j < r; j++){
                remaining[i][j] = required[i][j] - allocated[i][j];
            }
        }

        int count = 0, k;//count keeps track of how many processes have completed
        bool check;//keeps track of whether at least one process is completed in an iteration or else deadlock condition will be achieved
        bool flag[p] = {false};//keep track of whether processes are finished or not
        func(3);
        //To find safe state if it exists
        while(count < p){
            check = false;
            for(i = 0; i < p; i++){
                if(flag[i]) continue;
                int l=0;
                //Checks to find whether the available resources are enough to satisfy the requirements of the process
                for(j = 0; j < r; j++)
                    if(available[j] >= remaining[i][j]) l++;
                //If the requirements are satisfied modify the flag, order and the number of available resources
                if(l == r){
                    flag[i] = true;
                    order[count] = i+1;
                    count++;
                    check= true;
                    for(k = 0; k < r; k++)
                        available[k] += allocated[i][k];
                }
            }
            if(!check){
                cout << BOLDRED << "This is an unsafe state, there is no possible safe sequence of allocation for the processes to finish its remaining work.\n";
                break;
            }
        }

        if(count == p){
            cout<< BOLDYELLOW << "The current allocation is in a safe state, the processes can avoid a deadlock.\n\n";
            cout << BOLDYELLOW << "The safe sequence of completion is: \n\n\n" << BOLDWHITE;
            for(i = 0; i < p; i++){
                cout << BOLDWHITE << "Process " << order[i];
                if(i != p - 1)
                    cout << " -> ";
            }
        }
}
