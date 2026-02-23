#include<iostream>
using namespace std;


int integerSumReturn(int a, int b) {
    int result = a + b;
    cout<< "addr : " << &result <<"\n";
    return result;
}
int main() {
    int a{2} , b{5};
    int result = integerSumReturn(a,b);
    cout << "addr : " << &result <<"\n"; // gets different address for result.   
    return 0;
}