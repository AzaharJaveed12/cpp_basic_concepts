/*

    Feels like : What we are passing should be differnt.
        ex: fun(x)
            fun(&x)

*/

#include<iostream>
#include<string>

#include "OpetionalParamsFunction.h"
#include "ArgOrdersAndNumberOfArgs.h"
#include "PointerParemsFunction.h"
#include "ReferenceParamsFunction.h"

using namespace std;

void printAge(int age) {
    cout <<"[overloaded]  integer-age  ::" << age << "\n";
}

void printAge(double age) {
    cout << "[overloaded] double-age  ::" << age <<"\n";
}

void printAgeDetails(string str) {
    cout <<"[optionalParams] string ::" << str << "\n";
}

void min(int x, int y) {
    cout << "[PointerOverloading] (int,int)\n";
}

void min(int* x , int* y) {
    cout << "[PointerOverloading] (int*,int*)\n";
}

//void square(int x) {
    //x *= x;
    //cout << "[ReferenceOverloading] (int) " << x;
//}

void square(int& x) {
    x *= x;
    cout << "[ReferenceOverloading] (int&) " << x << "\n";
}

void square(const int& x) {
    // x *= x; Cannot change x.
    cout << "[ReferenceOverloading] (const int&) " << x;
}

void cube(const int& x) {
    cout << "[ReferenceOverloading] (const int&) " << x;
}

int main() {
   // OpetionalParamsFunction.h
    int ageI = 4;
    printAge(ageI);        // No error
    double ageD{5.5};
    printAge(ageD);        // no Error
    // printAge();          // Error
    printAgeDetails("abcd");
    
    // PointerParemsFunctions.h
    int x{5} , y{6};
    min(x,y);  
    min(&x,&y);

    const int& a{5};
    square(x); // suqare(int&);
    square(3); // square(const int&)
    square(a); // square(cont int&)
    cout << x <<"\n";
   // square(x);
   // cout <<x;

    cube(x); // cube(const int&)
    cube(4); // cube(const int&)
    cube(a); // cube(const int&)
    return 0;
}
