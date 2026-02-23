#include <iostream>
#include "point.h"

namespace geometry {
    Point::Point(const int& x, const int& y): x{new int(x)} , y{new int(y)} {}

    void Point::print_point() const {
        std::cout << " [x] = " << *x << "      [y] = " << *y << "\n";
    }

    const int* Point::get_x() const {
        return x;
    }

    const int* Point::get_y() const {
        return y;
    }

    Point::~Point() {
        std:: cout << "point got deleted [x , y] = [" << *x << " , " <<*y << "]\n";
        delete x;
        delete y;
    }
}