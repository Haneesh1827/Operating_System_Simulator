#ifndef HRRF
#define HRRF
#include<vector>
#include"utilities.hpp"
using namespace std;
void hrrf(vector<process> &proc_list);
double Calculate_res_ratio(process &P, int curr_time);
#endif