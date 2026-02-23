#include<iostream>
void passByConstValue(const int a) {
    // ++a;
    std::cout<< "func : \n         addr: " << (&a) <<" -----> value: " << a << "\n ";
}