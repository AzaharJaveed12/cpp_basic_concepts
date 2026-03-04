#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int& ref_x = x;
    int var_ref_x = ref_x; // var_ref_x is not reference to x.
    cout << x << " " << var_ref_x << "\n";
    x++;
    cout <<x << " " << var_ref_x << "\n";
    return 0;
}