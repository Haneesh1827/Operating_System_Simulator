#ifndef mvt
#define mvt
#include<iostream>
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
class proc{
    public:
    int size;
    int id;
};
class node{
    public:
    int size;
    int flag;
    int id;
    node *prev;
    node *next;
};
void fu(size_t max);
int mvt_input_choice();
void Insert_ff(node *&head, int &total_free_space);
void Insert_bf(node *&head, int &total_free_space);
void Insert_wf(node *&head, int &total_free_space);
void firstfit();
void bestfit();
void worstfit();
void display(node *head);
void remove(node *head, int &total_free_space);
void Continous_mem_alloc();
#endif