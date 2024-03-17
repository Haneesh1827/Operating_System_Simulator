#include"disk.hpp"

void Look_main(Arg arg){
    long int j=1 <<16;
    for (size_t i = 0; i < 6; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
    cout << BOLDMAGENTA << "LOOK Simulation\n\n\n";
    
  
    vector<int> left, right;
    vector<int> seek_sequence;
    int n = arg.seekreq.size(), i;
    // separate the requests partiioned by the intial head position
    for(i = 0; i < n; i++) {
        if(arg.seekreq[i] < arg.startseekloc)
            left.push_back(arg.seekreq[i]);
        else
            right.push_back(arg.seekreq[i]);
    }
    
    //sort left and right vectors
    
    sort(right.begin(), right.end());
    sort(left.begin(), left.end(), greater<int>());
    
    for(int num: right)
        seek_sequence.push_back(num);
    for(int num: left)
        seek_sequence.push_back(num);
    
    requests_entered(arg);
    cout << BOLDCYAN << "Intial position of head: " << BOLDWHITE << arg.startseekloc << "\n\n";
    cout << BOLDCYAN << "Intial direction of head: "<< BOLDWHITE << "Towards Right" << "\n\n"; 
    cout << BOLDCYAN << "Length of the disk: " << BOLDWHITE << arg.disk_size << "\n\n\n\n";
    cout << BOLDCYAN << "Head Movement: " << BOLDWHITE;
    
    cout << arg.startseekloc << " ---> ";
    for(i = 0; i < n-1; ++i)
        cout << seek_sequence[i] << " ---> ";
    cout << seek_sequence[i];
    cout << RESET;
}
