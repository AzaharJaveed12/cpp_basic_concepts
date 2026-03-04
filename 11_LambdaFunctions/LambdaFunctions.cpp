#include<iostream>

using namespace std;

int main () {
    int a = 5;
    int b = 10;
    int x = 3, y =6;
    auto funca = []() {
        cout << "Simple lambda function \n" ;
    };

    auto funcb = [](int x, int y) {
        x++;
        y++;
        cout << "Lambda params : " << x << " " << y << "\n";
    };

    auto funcc = [a,b]() {
       // a++; b++; // cannot change this value
        cout << "Lambda with context list " << a << " " << b <<"\n";
    };

    auto funcd = [&a,&b](int x, int y) {
        a++; b++;
        cout << "Lambda with context & params " << a <<" " << b <<" " <<x << " " <<y <<"\n";
    };

    auto funce = [=](int x,int y) {
        // a++;
        x++;
        cout << "lambda with copied value from above scope " <<a << x <<"\n";
    };

    auto funcf = [&]() {
        x++;y++;
        cout << "lambda with reference scope " <<x <<" " <<y << "\n";
    };

    funca();
    funcb(x,y);
    funcc();
    funcd(a,b);
    funce(a,b);
    funcf();

    return 0;
}