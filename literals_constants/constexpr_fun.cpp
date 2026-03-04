#include <iostream>
 
using namespace std;

constexpr int fun(int x) {
    return x * x;
}

int main() {
    constexpr int a = fun(5);        // compile time
    constexpr int x = 4;             // compile time variable
    constexpr int x_square = fun(x); // compile time
    int y = 2;                       // run-time variable
    //constexpr int y_square = fun(y); // y is not constexpr or compiletime constant soo cant store its result in constexpr.
    int y_square = fun(y);           // run-time evaluation of fun
    return 0;
}