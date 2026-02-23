#include<iostream>
using namespace std;

int fun();

int main() {
    int a = 5;
    cout<< "" <<"""" << endl;
    cout<< "";
    fun();
    return 0;
}

int fun() {
    int e = 6;
    char c = 'a';
    int e1 = 99;
    int *p = new int;
    *p = e + e1;
    ++*p;
    string j = "kk";
    j = "xd";
    cout << "Value of j: " << j << endl;
    return 1;
}