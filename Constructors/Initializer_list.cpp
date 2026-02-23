#include <iostream>
#include <cassert>

using namespace std;
/*
    1. Member variables of class should be public to use default initializerList.
    2. Narrowing conversion not allowed. (we cannot pass int and try to make it double. )
    3. 
*/
struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x) , y (y) {
        cout << "Constructor got called \n";
    }

    Point(initializer_list<double> list) {
        cout << "Constructor of initializer list got called \n";
        assert(list.size() == 2);
        x = *(list.begin());
        y = *(list.begin() + 1);
    }
};

int main () {
    Point p1{10.4 , 10.5};    
    Point p0{10 ,10}; // we we have all default constructos then this will throw error
    Point p01(10,11);
    
    Point p3{1.1,2.2};
    return 0;
}