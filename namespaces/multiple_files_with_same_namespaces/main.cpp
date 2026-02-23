#include <iostream>
#include "point.h"
#include "line.h"
#include "cylinder.h"

int main() {
    const int x_s = 0 , y_s= 0 , x_e = 5 , y_e = 5;
    geometry::Point start(x_s , y_s);
    geometry::Point end(x_e , y_e);
    start.print_point();
    std::cout << "\n";
    end.print_point();
    std::cout << "\n";

    geometry::Line line(&start , &end);
    std:: cout << line.get_distance() << "\n";
    line.print_line();

    int r = 10 , h = 20;
    geometry::Cylinder cylinder(r , h);
    cylinder.print_cylinder();
    cylinder.volume();
    std::cout << "\n";

    return 0;
}