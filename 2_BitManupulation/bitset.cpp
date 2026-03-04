#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<32> mask;
    mask.flip(3);
    cout << mask <<"\n";
    mask.set(1);
    cout << mask << "\n";
    return 0;
}