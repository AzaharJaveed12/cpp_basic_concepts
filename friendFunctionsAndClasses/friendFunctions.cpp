#include <iostream>

using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(const double& radius): radius{radius} {}

    friend double area(const Circle& circle);
};

double area(const Circle& circle ) {
    cout << " private member data of circle from outside function : " << circle.radius <<"\n";
    return 3.14 * circle.radius * circle.radius;
}

int main () {
    Circle circle{5.4};
    cout << area(circle) << "\n";
    return 0;
}