#include <iostream>
 
using namespace std;

/*
    100% compiletime gaurenteed when variable is constexpr.
    which ever variables get evaluated during compile-time, those variables only used to initialize constexpr.
    
    which ever variables initialized with const with some literals, can only be used in constexpr.
    can we have refs & ptrs for constexpr variables ?
*/
int main() {
    int x = 5;                  // this cannot use in cexpr_x
    const int c_x = x;          // cannot use because this also evaluates at runtime only.
    const int c_x1 = 5;         // can use in cexpr_x as it is constant
    constexpr int cexpr_x{c_x1};
    // cexpr_x = 7;            // cexpr_x is constant itself. soo it cannot modifiable.

    // ref & pointers
    // constexpr int& cexpr_ref_x = cexpr_x;
    // constexpr const int* cexpr_ptr_x = &c_x1;
    return 0;
}