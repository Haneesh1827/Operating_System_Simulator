#ifndef disk_driver
#define disk_driver


#include"Utilities.hpp"
using namespace std;
void requests_entered(Arg arg);
void Scan_main(Arg arg);
void Look_main(Arg arg);
void Fcfs_main(Arg arg);
void Cscan_main(Arg arg);
void Clook_main(Arg arg);
void take_input(Arg &arg);
int dpolicy_choice();
int dpost_policy_choice();
void disk_main();
#endif
