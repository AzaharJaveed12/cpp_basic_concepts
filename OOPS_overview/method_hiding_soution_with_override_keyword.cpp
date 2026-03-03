#include <iostream>

using namespace std;

class A
{
public:
    virtual void f(int a)
    {
        cout << "A::(int) " << a << "\n";
    }

    void f(double a)
    {
        cout << "A::(double) " << a << "\n";
    }
};

class B : public A
{
public:
    /*
        if this function is not marked as virtual in base class, then it will throw error.
    */
    void f(double a) override
    {
        cout << "B:: (double) " << a << "\n";
    }
};

int main()
{
    B b;

    b.f(10); // caling with int but derived class doble method gets called.

    return 0;
}