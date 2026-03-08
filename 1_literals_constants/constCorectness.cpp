#include <iostream>

using namespace std;

void fun(const int& x) {
    int x_copy = x;
    cout << x_copy << "\n";
}

void fun(const string& x) {
    std::string x_copy = x;
    cout << x_copy <<"\n";
}

int main() {
    int x = 4;
    fun(x);

    string str = "abcd";
    fun(str);
    return 0;
}