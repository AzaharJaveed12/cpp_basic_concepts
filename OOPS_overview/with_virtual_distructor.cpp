#include <iostream>
#include <memory>
using namespace std;

class A{
public:
    A() {
        cout << "+A\n";
    }

    virtual ~A() {
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

    cout << "------------\n";

    {
        unique_ptr<A> _b = make_unique<B>(); // construction & delition taken care by scope
    }
    return 0;
}