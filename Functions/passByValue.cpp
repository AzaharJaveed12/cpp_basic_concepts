#include<iostream>
void passByValue(int a) {
    ++a;
    std::cout<< "func : \n         addr: " << (&a) <<" -----> value: " << a << "\n ";
}