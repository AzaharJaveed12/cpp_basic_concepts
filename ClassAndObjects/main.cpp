#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
    Circle c1;
    Circle c2(2.5);
    Circle c3(3.5, 1 , 2);

    Circle *pc1 = new Circle();
    Circle *pc2 = new Circle(4.5);
    Circle *pc3 = new Circle(5.5,3,4);

    Circle& c4 = c3;

    c1.set_radius(1.2).set_positionX(5).set_positionY(6);
    double area_c1 = c1.print_circle_details()->calculate_area();
    double diameter_c1 = c1.print_circle_details() -> calculate_diameter();
    cout << area_c1 << " " <<diameter_c1 <<"\n";

    pc1 -> set_radius(10.4).set_positionX(5).set_positionY(9);
    double area_pc1 = pc1 -> print_circle_details() -> calculate_area();
    double diameter_pc1 = pc1 -> print_circle_details() -> calculate_diameter();
    cout << area_pc1 <<" " << diameter_pc1 <<"\n";

    delete pc1;
    delete pc2;
    delete pc3;

    return 0;
}