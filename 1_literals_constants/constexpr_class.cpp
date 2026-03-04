#include <iostream>

using namespace std;

class Vec {
public:
    int x , y;
    constexpr Vec(int x , int y): x{x} , y{y} {};
    // this is marked as constant because v is const object created. Then only we can call this.
    constexpr int add() const { return x + y; }
};

int main() {
    constexpr Vec v{2,3};
    static_assert(v.add() == 5);
    return 0;
}