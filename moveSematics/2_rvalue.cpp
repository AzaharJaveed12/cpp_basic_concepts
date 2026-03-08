#include <iostream>
using namespace std;

double add(int a , int b) {
    return a + b;
}

int main() {
    int x {5};
    int y{20};
    int z{30};

    int *ptr = &x;

    // lvalue
    z = (x + y); // tempora ry created and added to thsese variables z & sum
    double&& sum = add( x , y);

    // rvalue
    int&& outcome = x + y; // this extendes the lifetime of temporary created and names it outocme
    double&& sum = add( x , y); // temporary life extended and places in sum
    std::cout << "Z : " << z << std::endl; 
    return 0;
}