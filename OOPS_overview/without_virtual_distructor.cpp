#include <iostream>

using namespace std;

class A{
public:
    A() {
        cout << "+A\n";
    }

    ~A() {
        cout << "~A\n";
    }
};

class B: public A {
public:
    B() {
        cout << "+B\n";
    }

    ~B() {
        cout << "~B\n";
    }
};

int main() {
    {
        B b;
        A& a = b;  // this is just a ref variable.
    }
    cout << "-----------\n";
    {
        A *_b = new B();
        delete _b;
    }
    return 0;
}