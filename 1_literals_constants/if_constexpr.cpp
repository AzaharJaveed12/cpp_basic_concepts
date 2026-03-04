#include <iostream>

int main() {
    constexpr int x = 19;

    // available from c++17 only...!!
    if constexpr ( x >= 18) {
        std:: cout << "Major\n";
    } else {
        std:: cout << "Minor\n";
    }

    return 0;
}