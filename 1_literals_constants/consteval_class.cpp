#include <iostream>

using namespace std;

class Token {
public:
    consteval Token(int x): x{x} {}   
private:
    int x;
};

consteval Token make_token(int x) {
    if( x < 0 ) throw "invalid token";
    return Token{x};
}

int main() {
    constexpr Token token = make_token(5);
    return 0;
}