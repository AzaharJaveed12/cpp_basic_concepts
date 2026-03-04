#include<iostream>
void passByPointer(int* age) {
    ++(*age);
    std::cout<< "func : \n         addr: " << age <<" -----> value: " << *age << "\n ";
}