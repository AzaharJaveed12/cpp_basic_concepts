#include <iostream>

using namespace std;


int main () {
    int arr[5] = {1 ,2 , 3 , 4 , 5};

    // c++20
    for(int sum{0}; const auto& ele: arr) {
        sum += ele;
        cout << sum << " ";
    }

    return 0;
}