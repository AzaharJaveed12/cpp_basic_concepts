#include "point.h"

#ifndef __LINE_
#define __LINE_

namespace geometry {
    class Line {
    public:
        Line() = delete;
        Line(const Point* start,const Point* end);
        void print_line() const;
        double get_distance() const;
        ~Line();
    private:
        const Point* start;
        const Point* end;
    };
}

#endif