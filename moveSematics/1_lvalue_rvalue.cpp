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

    z = (x + y); // temporary created and added to thsese variables z & sum
    double sum = add( x , y);
    
    std::cout << "Z : " << z << std::endl; 
    // std::cout << "&(x + y)" << (&(x + y)) << "\n";
    return 0;
}