#ifndef SJF
#define SJF
#include"utilities.hpp"
#include<vector>
using namespace std;
class ComparePriority_sjf {
public:
    bool operator()(const process* a, const process* b);
};
void sjf(vector<process> &proc_list);
#endif