#include <cmath>
#include <iostream>
#include "line.h"

namespace geometry {
    Line::Line(const Point* start, const Point* end):start{start} , end{end} {}

    void Line::print_line() const {
        std::cout << " [from] ";
        start -> print_point();
        std::cout <<"\n";
        std::cout << " [to]   ";
        end -> print_point();
        std::cout << "\n";
    }

    double Line::get_distance() const {
        return std::sqrt(pow(*(end -> get_x()) - *(start -> get_x()) , 2) + pow(*(end -> get_y()) - *(start -> get_y()) , 2));        
    }

    Line::~Line() {
        std::cout << "line got deleted \n";
        // we didnt allocate memory for this so we cannot delete this.
        // delete start;
        // delete end;
    }
}
