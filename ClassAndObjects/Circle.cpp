#include "Constants.h"
#include "Circle.h"

Circle::Circle()
{
    radius = 0;
    midX = new int(0);
    midY = new int(0);
}

Circle::Circle(const double &radius)
{
    this->radius = radius;
    midX = new int(0);
    midY = new int(0);
}

Circle::Circle(const double &radius, const int &x, const int &y)
{
    this->radius = radius;
    this->midX = new int(x);
    this->midY = new int(y);
}

int Circle::get_positionX()
{
    return *(this->midX);
}

int Circle::get_positionY()
{
    return *(this->midY);
}

Circle &Circle::set_radius(const double &radius)
{
    this->radius = radius;
    return *this;
}

Circle &Circle::set_positionX(const int &midX)
{
    *(this->midX) = midX;
    return *this;
}

Circle &Circle::set_positionY(const int &midY)
{
    *(this->midY) = midY;
    return *this;
}

double Circle::calculate_diameter()
{
    return radius * 2 * PI;
}

double Circle::calculate_area()
{
    return radius * radius * PI;
}

Circle* Circle::print_circle_details()
{
    std::cout << "Radius : " << radius << "  midX : " << *midX << " midY : " << *midY << "\n";
    return this;
}

Circle::~Circle()
{
    std::cout << radius << "<-- Destructor \n";
    delete midX;
    delete midY;
}
