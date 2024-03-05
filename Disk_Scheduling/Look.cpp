
#include <bits/stdc++.h> 
using namespace std; 


// ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"      
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"      
#define WHITE   "\033[37m"
  
int disk_size = 1000; 

/*void LOOK(int arr[], int head, string direction) 
{ 
    int seek_count = 0; 
    int distance, cur_track; 
    vector<int> left, right; 
    vector<int> seek_sequence; 
  
    // appending values which are 
    // currently at left and right 
    // direction from the head. 
    for (int i = 0; i < size; i++) { 
        if (arr[i] < head) 
            left.push_back(arr[i]); 
        if (arr[i] > head) 
            right.push_back(arr[i]); 
    } 
  
    // sorting left and right vectors 
    // for servicing tracks in the 
    // correct sequence. 
    std::sort(left.begin(), left.end()); 
    std::sort(right.begin(), right.end()); 
  
    // run the while loop two times. 
    // one by one scanning right 
    // and left side of the head 
    int run = 2; 
    while (run--) { 
        if (direction == "left") { 
            for (int i = left.size() - 1; i >= 0; i--) { 
                cur_track = left[i]; 
  
                // appending current track to seek sequence 
                seek_sequence.push_back(cur_track); 
  
                // calculate absolute distance 
                distance = abs(cur_track - head); 
  
                // increase the total count 
                seek_count += distance; 
  
                // accessed track is now the new head 
                head = cur_track; 
            } 
            // reversing the direction 
            direction = "right"; 
        } 
        else if (direction == "right") { 
            for (int i = 0; i < right.size(); i++) { 
                cur_track = right[i]; 
                // appending current track to seek sequence 
                seek_sequence.push_back(cur_track); 
  
                // calculate absolute distance 
                distance = abs(cur_track - head); 
  
                // increase the total count 
                seek_count += distance; 
  
                // accessed track is now new head 
                head = cur_track; 
            } 
            // reversing the direction 
            direction = "left"; 
        } 
    } 
  
    cout << "Total number of seek operations = "
         << seek_count << endl; 
  
    cout << "Seek Sequence is" << endl; 
  
    for (int i = 0; i < seek_sequence.size(); i++) { 
        cout << seek_sequence[i] << endl; 
    } 
} */
  
// Driver code
/*int main(){ 
    int n, head;
    cout << RED << "Enter the number of disk requests: \n"; 
    cin >> n;
    vector<int> Requests(n);
    cout << RED << "Enter the "<< n << " seek requests: \n";
    for(int i = 0; i < n; i++){
        cin >> Requests[i];
    }
    cout << RED << "Enter the initial head position: \n";
    cin >> head;
    cout << RED << "Choose the disk scheduling alogrithm among the following options: \n" << RESET;
    cout << "\n 1. C-LOOK" << endl;
	cout << " 2. C-SCAN" << endl;
	cout << " 3. FCFS" << endl;
	cout << " 4. LOOK" << endl;
	cout << " 5. SCAN" << endl;
	cout << " 6. SSTF\n";
} */