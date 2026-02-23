#include <iostream>

using namespace std;
/*

Use auto when:
    1.Type is obvious from RHS
    2.Iterators
    3.Lambdas
    4.Range loops
    5.Complex STL types
    6.Clean production code


decltype(x) → type of x (int)
decltype((x)) → reference type (int&)
Use decltype when:
    1.Writing templates
    2.Perfect forwarding
    3.Return type deduction (complex)
    4.Preserving reference/const qualifiers
    5.Metaprogramming
    6.Expression type extraction

decltype(auto)

*/

const int x = 10;
const int& number() {
    return x;
}

int main() {
    // Simple data type deductions for auto
    auto var1{12};
    auto var2{13.0};
    auto var3{14.0f};
    auto var4{15.0l};
    auto var5{'e'};
    auto var6{123u};
    auto var7{1234l};
    auto var8{1234ul};

    // Assigning some constant variables to create a new variable.
    const int c_x = 5;
    auto auto_x{c_x};  // Constantness vanished..!!
    decltype(c_x) decl_x = c_x; // constantness preserved..!!    
    decltype((c_x)) decl_ref_x = c_x; // constantness & reference preserved..!!

    // Assigning some reference variable to create a new variable
    int var_y{10};
    int& ref_y = var_y;
    auto auto_y = ref_y; // reference vanished
    decltype(ref_y) decl_y = ref_y; // reference preserved.

    // decltype(auto)
    auto auto_res = number(); // return value is deduced to int
    decltype(auto) res = number(); // retruned value constentness & reference is preserved.
    return 0;
}