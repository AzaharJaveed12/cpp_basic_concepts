#include <iostream>
#include <set>

using namespace std;

int main() {
    int arr[5];                                     // continious block of memory.
    cout << size(arr) <<"\n";                       // c++17 introduced
    cout << (sizeof(arr) / sizeof(arr[0])) << "\n"; // before to find length.
    return 0;
}