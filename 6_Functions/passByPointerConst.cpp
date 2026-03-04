#include<iostream>
void passByPointer(const int* age) {
    // ++(*age); // This line would cause a compilation error because age is a const pointer
    std::cout<< "func : \n         addr: " << age <<" -----> value: " << *age << "\n ";
}