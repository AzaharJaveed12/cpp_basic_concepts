#include <iostream>

using namespace std;

class A{
public:
  virtual void f(int a) {
    cout << "A::(int) " << a << "\n";
  }

  void f(double a) {
    cout << "A::(double) " << a << "\n";
  }
};

class B: public A {
public:
    using A::f;
    void f(double a) {
        cout << "B:: (double) " << a << "\n";
    }
};

int main() {
    B b;

    b.f(10);
    return 0;
}