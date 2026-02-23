#ifndef __POINT__
#define __POINT__

namespace geometry {
    
    class Point {
    public:
        Point() = delete;
        Point(const int& x ,const int& y);
        void print_point() const;
        const int* get_x() const;
        const int* get_y() const;
        ~Point();
    private:
        const int* x;
        const int* y;
    };
}

#endif