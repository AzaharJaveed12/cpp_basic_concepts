#include <iostream>

using namespace std;

int main () {
    int x = 10;
    int y = 10;
    int z = 10;

    const int* p_x = &x;
    // *p_x = x + 1;   // cannot modify value
    p_x = &y;          // can point to another address

    int* const p_y = &y;
    *p_y = y + 1;      // can modify value
    // p_y = &x;       // can't modify the address pointing by this pointer.

    int const* p_z = &z;
    // *p_z = z + 1;   // cant modify the value
    p_z = &y;          // can modify the address

    const int* const p_xx = &x;
    // *p_xx = x + 1;   // cant modify the value & addr
    // p_xx = & y;
    return 0;
}