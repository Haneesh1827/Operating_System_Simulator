#include"pag_replacement.hpp"


void Fifo(int num_frames){
    f(3);
    cout << BOLDMAGENTA << "FIRST IN FIRST OUT";
    f(3);
    Page* frames[num_frames];
    int faults=0, reqs=0,pid,i,time=0,min,min_index;
    int choice;
    // initialize each frame to empty.
    for(i=0;i<num_frames;++i)
        frames[i]=nullptr;
    
    //  Print user menu.
    cout << BOLDGREEN << "Choose the option\n\n" << BOLDWHITE;
    cout << " 1.Request Page\n";
    cout << " 2.Stop Adding page\n";
    cout << " 0.Exit\n";

    while (true)
    {
        // Get user Input
        cout << BOLDGREEN <<"\nYour choice: " <<BOLDWHITE;
        cin >> choice;
        switch(choice){
            case 1:
                cout << BOLDCYAN <<"\nEnter Page id : " << BOLDWHITE;
                cin >> pid;
                
                // increment requests
                ++reqs;
                f(2);
                for (i=0;i<num_frames;++i){
                    if(frames[i] && frames[i]->id == pid){
                        cout << BOLDBLUE <<"Page " << BOLDWHITE << pid << BOLDBLUE << " is already present in memory." << "\nLocated at frame " << BOLDWHITE << i;
                        f(2);
                        break;
                    }
                }
                
                // Exit case if page was found.
                if(i < num_frames)
                    break;
                else
                    ++faults;

                // Search for Empty Frames
                for(i=0;i<num_frames;++i){
                    if(frames[i]==nullptr){
                        frames[i] = new Page(pid, time++);
                        cout << BOLDYELLOW << "Page " << BOLDWHITE << pid << BOLDYELLOW << " is accomodated in frame " << BOLDWHITE << i;
                        f(2);
                        break;
                    }
                }
                
                // exit case, if frame has been assigned
                if (i < num_frames)
                    break;
                
                min = frames[0]->timestamp;
                min_index = 0;
                
                // find the first arrived process
                for(i=1;i<num_frames;++i){
                    if(min>frames[i]->timestamp){
                        min = frames[i]->timestamp;
                        min_index = i;
                    }
                }
                cout << BOLDYELLOW << "Page " << BOLDWHITE << pid << BOLDYELLOW << " was accomodated in Frame " << BOLDWHITE << min_index << BOLDYELLOW<<" after removing page " << BOLDWHITE <<frames[min_index]->id;
                delete(frames[min_index]);
                frames[min_index] = new Page(pid,time++);
                f(2);
                break;
            case 2:
                cout << BOLDRED << "\nNumber of page faults  => " << BOLDWHITE << faults <<"\n";
                cout << BOLDRED <<"Page fault ratio       => " << BOLDWHITE <<(double) faults / reqs << "\n\n"; 
                break;
            default:
                cout << BOLDRED <<"Invalid key\n\n";
                break;
        }
            
    }
    return;
}