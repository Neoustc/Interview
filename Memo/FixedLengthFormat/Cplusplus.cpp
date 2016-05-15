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
#include <cstdio>
#include <iostream>

int main() {
    char buffer[5];
    // Prints: 0001
    snprintf(buffer, 5, "%04d", 1);
    std::cout << buffer << '\n';
    // Prints: 1234 (not the 5)
    snprintf(buffer, 5, "%04d", 12345);
    std::cout << buffer << '\n';
}
