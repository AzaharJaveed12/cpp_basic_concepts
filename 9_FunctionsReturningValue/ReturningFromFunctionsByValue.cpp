#include<iostream>
using namespace std;


int integerSumReturn(int a, int b) {
    int result = a + b;
    cout<< "addr : " << &result <<"\n";
    return result;
}

string concating(const string& a ,const string& b) {
    string res = a + b;
    cout << "[concating] : " << &res << "\n";
    return res;
}

// ref send properly.
int& min(int &a , int& b) {
    return a < b ? a : b;
}

// ref of local var sent soo error.
int& min_internalVarRefSent(int &a , int& b) {
    int res =  a < b ? a : b;
    return res;
}

int main() {
    int a{2} , b{5};
    int result = integerSumReturn(a,b);
    cout << "addr : " << &result <<"\n";     // gets different address for result. 
    
    string res = concating("abc" , "def"); // same address as computed res inside concating
    cout << "[main res of concating] : " << &res <<"\n";

    int& min_res = min(a , b);
    int& min_internal_ref_res = min_internalVarRefSent(a, b);
    cout <<min_res << "  " << min_internal_ref_res << " END\n"; // code crashed because of undefined reference has been used.
    return 0;
}