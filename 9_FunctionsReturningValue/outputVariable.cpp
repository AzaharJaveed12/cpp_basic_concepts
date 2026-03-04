#include<iostream>

using namespace std;


void maximumVal(const int &a, const int &b , int &c) {
    (a < b ) ? (c = b) : (c = a);
}

void minimumVal(int* const a, int* const b, int* c) {
    (*a < *b) ? (*c = *a) : (*c = *b);
}

int main() {
    int a{5} , b {6} , c{0};
    maximumVal(a,b,c);
    cout << c << " <-- Maximum \n";
    minimumVal(&a , &b, &c);
    cout << c << " <--- Minimum\n";
    cout << a << " " << b  << " " << "\n";
    return 0;
}