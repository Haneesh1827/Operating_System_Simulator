#include "pag_replacement.hpp"

void Lru(int num_frames){
    f(3);
    cout << BOLDMAGENTA << "LEAST RECENTLY USED PAGE REPLACEMENT";
    f(3);
    // Declare and initialize variables

    class Page* frames[num_frames];
    int faults=0, reqs=0,pid,i,time=0,min,min_index;
    int choice;
    
    // initialize each frame to empty.
    for(i=0;i<num_frames;++i)
        frames[i]=nullptr;
    
    //  Print user menu.
    cout << BOLDGREEN << "Choose the option\n" << BOLDWHITE;
    cout << "\n1. Request Page\n";
    cout << "2. Stop Adding page\n";
    cout << "0. Exit\n\n";
    
    // Menu Driven Logic
    while (true){
        // Get user Input
        cout << BOLDGREEN << "Your choice: " << BOLDWHITE;
        cin >> choice;

        // Switch Case of choices
        switch(choice){
             // Case 1 => Addition of Page.
            case 1:
                // Take User Input
                cout << BOLDGREEN "\nEnter Page id: " << BOLDWHITE;
                cin >> pid;
                
                // increment requests
                ++reqs;
                
                // Linear search for requested page in
                // available frames
                f(2);
                for (i=0;i<num_frames;++i){
                    
                    // If Page is found
                    // Update user
                    if(frames[i] && frames[i]->id == pid){
                        
                        // Update access time to current time.
                        frames[i]->timestamp = time++;
                        cout << BOLDBLUE <<"Page " << BOLDWHITE << pid << BOLDBLUE << " is already present in memory." << "\nLocated at Frame " << BOLDWHITE << i;
                        f(3);
                        break;

                    }
                }
                
                // Exit case if page was found.
                // Else increment number of page faults.
                if(i < num_frames)
                    break;
                else
                    ++faults;

                // Search for Empty Frames
                for(i=0;i<num_frames;++i){
                    // Accomodate the page in the first
                    // Empty frame found.
                    if(frames[i]==nullptr){
                        frames[i] = new Page(pid, time++);
                        cout << BOLDYELLOW << "Page " << BOLDWHITE << pid << BOLDYELLOW << " is accomodated in Frame " << BOLDWHITE << i;
                        f(3);
                        break;
                    }
                }
                
                // exit case, if frame has been assigned
                if (i < num_frames)
                    break;
                
                // Initialize variables 
                // to search for least recently used process 
                min = frames[0]->timestamp;
                min_index = 0;
                
                // find the LRU process.
                for(i=1;i<num_frames;++i){
                    if(min>frames[i]->timestamp){
                        min = frames[i]->timestamp;
                        min_index = i;
                    }
                }
                
                // Replace LRU with requested page 
                cout << BOLDYELLOW << "Page " << BOLDWHITE << pid << BOLDYELLOW << " was accomodated in Frame " << BOLDWHITE << min_index << BOLDYELLOW<<" after removing Page " << BOLDWHITE <<frames[min_index]->id;
                
                // Delete LRU from memory. 
                delete(frames[min_index]);

                // Add requested page to frame.
                frames[min_index] = new Page(pid,time++);
                f(3);
                break;
            
            // Page request are completed
            // Update user with runtime statistics    
            
            case 2:
                cout << BOLDRED << "\nNumber of page faults  => " << BOLDWHITE << faults <<"\n";
                cout << BOLDRED <<"Page fault ratio       => " << BOLDWHITE <<(double) faults / reqs << "\n\n"; 
                break;
            case 0:
                return;
            default:
                cout << BOLDRED << "Invalid key!\n\n"; 
                break;
            // Default case
            // exit to main menu
        }
            
    }
    return;
}