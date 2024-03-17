#include "pag_replacement.hpp"
void f(size_t max){
    long int j=1 <<16;
    for (size_t i = 0; i < max; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
}
void page_replacement() {
    f(3);
    cout << BOLDMAGENTA << "PAGE REPLACEMENT ALGO";
    f(3);
    int choice, num_frames;
    // Get number of frames
   

    while(true){
        cout << BOLDGREEN << "Enter the number of frames : " << BOLDWHITE;
        cin >> num_frames;
        f(3);
        cout << BOLDGREEN << "Choose Algorithm to simulate\n\n" << BOLDWHITE ;
        cout << "\n1. First In First Out [fifo]\n";
        cout << "2. Least Recently Used [lru]\n";
        cout << "3. Most Recently Used  [mru]\n";
       
        cout << "0. Exit\n\n";
        cout << BOLDGREEN << "Your choice : " << BOLDWHITE;
        cin  >> choice;
        switch(choice){
            case 0: 
                return;
            case 1:
                Fifo(num_frames);
                break;
            
            case 2:
                Lru(num_frames);
                break;
            case 3:
                Mru(num_frames);
                break;          
            default:
                cout << BOLDRED << "Invalid key!\n\n"; 
                break;
        }
        if(choice == 0)
            break;
    }
    return;
}