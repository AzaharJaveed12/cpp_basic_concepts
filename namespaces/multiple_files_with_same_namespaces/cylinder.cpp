#include <iostream>
#include <cmath>
#include "cylinder.h"

namespace geometry {
    Cylinder::Cylinder(const int& radius , const int& height): radius{radius} , height{height} {}
    
    void Cylinder::print_cylinder() const  {
        std::cout << " [radius] = " << radius << " [height] = " << height << "\n";
    }

    double Cylinder::volume() const {
        return PI * radius * radius * height;
    }

    Cylinder::~Cylinder() {
        std:: cout << " [cylinder] got deleted\n";
    }
}