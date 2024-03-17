#include"disk.hpp"

void Fcfs_main(Arg arg){
    long int j=1 <<16;
    for (size_t i = 0; i < 6; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }

    cout << BOLDMAGENTA << "FCFS Simulation\n\n\n";
    int i;
    int n = arg.seekreq.size();
    requests_entered(arg);
    cout << BOLDCYAN << "Intial position of head: " << BOLDWHITE << arg.startseekloc << "\n\n";
    cout << BOLDCYAN << "Intial direction of head: "<< BOLDWHITE << "Towards Right" << "\n\n"; 
    cout << BOLDCYAN << "Length of the disk: " << BOLDWHITE << arg.disk_size << "\n\n\n\n";
    cout << BOLDCYAN << "Head Movement: " << BOLDWHITE;
    
    cout << arg.startseekloc << " ---> ";
    for(i = 0; i < n-1; ++i)
      cout << arg.seekreq[i] << " ---> ";
    cout << arg.seekreq[i];
    cout << RESET; 
}