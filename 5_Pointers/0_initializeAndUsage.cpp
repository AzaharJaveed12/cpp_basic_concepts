#include <iostream>

using namespace std;

/*
    *ptr --> dereferincing the pointer.
    
*/

int main () {
    int var{32};          // var gets addr: 1000
    int* ptr{&var};      // ptr gets addrs : XYZ but ptr stores addr of var(1000)

    cout << "&var = " << (&var) << "    ptr = " << ptr << "\n";
    cout << "var = " << var << "       *ptr = " << (*ptr) << "\n";
    return 0;
}