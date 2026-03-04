#include <iostream>

using namespace std;

/* 
    this is overlaped with :
        fun(int x)
        fun(int& x)
        fun(const int x)
        fun(const int& x)
    reason : all takes input as fun(x); --> some times it craetes copies & sometimes it just sends the refs.
*/
void fun(int x) {
    cout << "[fun(int)] \n";
}

void fun(int& x) {
    cout << "[fun(int&)] \n";
}

/*
    this is overlaped with:
        fun(int* x)
        fun(const int*)
        fun(const int* const x)
    reason all takes input as fun(&x)
*/
void fun(int* x) {
    cout << "[fun(int*)] \n";
}

// redefination of fun(int x)
void fun(const int x) {
    cout << "[fun(const int)] \n";
}

void fun(const int& x) {
    cout << "[fun(const int&)] \n";
}

void fun(const int* x) {
    cout << "[fun(const int*)] \n";
}

// redefination of fun(const int* x)
void fun(const int* const x) {
    cout << "[fun(const int* const)] \n";
}

int main () {
    int x = 20;
    const int c_x = 30;
    const int* c_ptr_x = &x;

    //fun(x);
    // fun(c_x);
    // fun(c_ptr_x);

    // fun(&x);
    // fun(&c_x);
    return 0;
}