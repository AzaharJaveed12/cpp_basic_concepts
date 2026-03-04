#include <iostream>

using namespace std;

int main() {
    short x;
    unsigned short x1;
    clog << " [short] = " << sizeof(x) << " [unsigned short] = " << sizeof(x1) << "\n";

    int y;
    unsigned int y1;
    clog << " [int x] = " << sizeof(y) << " [unsigned int] = " << sizeof(y1) << "\n";

    long z;
    unsigned long z1;    
    long long z2;
    long long int z3;
    clog << " [long z] = " << sizeof(z) << " [unsigned long z1] = " << sizeof(z1) <<" [long long z2] = " << sizeof(z2) << " [long long int z3] = " << sizeof(z3) << "\n";

    float p;
    double q;
    long double r;
    clog << " [float p] = " << sizeof(p) << " [double q] = "<< sizeof(q) << " [long double r] = "<< sizeof(r) << "\n";

    /* initializations */
    int a;                //  garbage value
    int b(5.5);           // 5
    // int c{5.5};
    unsigned int ua;      // garbage value
    unsigned int ub(-3);  // +ve number overflow.

    clog << " [un-initialized int a]  = " << a << " [initialized int b()] = " << b <<"\n";
    clog << " [un-initialized int ua] = " << ua << " [initailized unsigned int ub] = " << ub << "\n";
    return 0;
}