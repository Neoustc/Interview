#include <iomanip> 

stringstream ss;
ss <<setfill('0') << setw(10) << i;//set fill char; set width
string s = ss.str();

************************************

C style

int n = 999;
char buffer[256]; 
sprintf(buffer, "%06d", n);
string str(buffer);

or 
snprintf(buffer, 5, "%04d", 1);
