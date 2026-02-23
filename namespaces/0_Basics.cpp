#include <iostream>
#include <cmath>


namespace accurate {
    double add(double x, double y);
    double sub(double x, double y);
}

namespace round_off {
    double add(double x, double y);
    double sub(double x, double y);
}

int main() {
    
    std::cout << accurate::add(5.5 , 6.2) << "\n";
    std::cout << round_off::add(5.5 , 6.2) << "\n";

    return 0;
}

namespace accurate {
    double add(double x , double y) { return y + x;}
    double sub(double x , double y) {return y - x; }
}

namespace round_off {
    double add(double x , double y) { return std::floor(y + x); }
    double sub(double x , double y) { return std::floor(y - x); }
}