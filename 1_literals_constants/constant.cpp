#include <iostream>
 
using namespace std;
/*
Constant rule of thumb:
    const variables can only assign to such variable which are not permissible to change data
    const int --can assign to--> const int&    const int*     

When will constant variables get memory ?
    compile-time or run-time ?
*/
int main() {
    int x = 5;
    const int c_x = x;

    x++;
    // c_x++; // we cannot modify constants.

    // constant & refs
    //int& r_c_x = c_x;        // c++ compailer stops pointing non-const variable to the same addr of c_x
    const int& c_r_c_x = c_x;  // const int& can hold const int reference
    const int* c_p_c_x = &c_x; // const int* can hold const int var address (constant to data pointing by pointer.)

    return 0;
}