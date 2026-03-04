#include <iostream>

using namespace std;
/*
    COMPAILER IS ABLE TO DEDUCE ONE DIMENTION..
*/
int main () {
    // int arrays
    int arr[][3] {
        {1 , 2 , 3 },
        {4 , 5, 6},
        {1},
        {2,3}
    };
    cout << size(arr) << "  <-- m   n --> " <<size(arr[0]) << "\n";

    // char array multi-dimentions
    char names[][10] {
        "Javeed" , 
        "shareef" , 
        "234"
    };
    return 0;
}