#include <iostream>
 
using namespace std;

/*
    Can main function also have static variables ?

    constinit :
        1. should be thread storage scope. (global)   OR  should be static
        2. We can modify their values at runtime. (thsese are mutable)
        3. strictly should defined at compile time.
*/

constexpr int fun(int x) {
    return x * x;
}
int main() {
    int x = 4;
    const int c_x = 5;
    static constinit int y = 5;

    // static constinit int x_square = fun(x);  // x is not able to evaluate at compile time soo throwing error.
    static constinit int c_x_square = fun(c_x); // c_x is evaluated at compile time soo it is not throwing error
    static constinit int const_square = fun(6); // 6 is constant and availbale at compile time.
    cout << y <<" constinit vars can change " <<(++y) << "\n";
    return 0;
}