#include <iostream>
#include "Constants.h"

class Circle {
    public:
        // COnstructors
        // Circle() = default;
        Circle(); 
        Circle(const double&); 
        Circle(const double&, const int&, const int&);
 
        // GETTERS
        double get_radius();
        int get_positionX();
        int get_positionY();

        // SETTERS
        Circle& set_radius(const double&);
        Circle& set_positionX(const int&);
        Circle& set_positionY(const int&); 

        //FUNCTIONS
        Circle* print_circle_details();
        double calculate_diameter();
        double calculate_area();

        // DESTRUCTOR
        ~Circle();
    private:
        double radius{0};
        int *midX , *midY;
};
