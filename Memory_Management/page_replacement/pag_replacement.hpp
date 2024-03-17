#ifndef pag_replacement
#define pag_replacement
#include<iostream>
#include<vector>
#include<unistd.h>
#include<cstddef>
using namespace std;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define UN "\e[4m"
class Page{
    public:
    int id;
    int timestamp;

    // Default initializer
    Page(int x, int y);
};
void f(size_t max);
void Fifo(int num_frames);    
void Mru(int num_frames);
void Lru(int num_frames);
bool search(int key, vector<int>& fr);
int predict(int pg[], vector<int>& fr, int pn, int index);
void optimalPage(int pg[], int pn, int fn);
void Optimal(int num_frames);
void page_replacement();
#endif