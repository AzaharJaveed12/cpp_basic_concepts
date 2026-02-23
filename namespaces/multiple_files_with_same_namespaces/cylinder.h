#ifndef __CYLINDER__
#define __CYLINDER__

namespace geometry {
    constexpr double PI = 3.14;
    class Cylinder {
    public:
        Cylinder() = delete;
        Cylinder(const int& radius , const int& height);
        void print_cylinder() const;
        double volume() const;
        ~Cylinder();
    private:
        const int radius;
        const int height;
    };
}

#endif