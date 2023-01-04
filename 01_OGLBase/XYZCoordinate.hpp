#pragma once

#include <istream>

struct XYZCoordinate {
    double x;
    double y;
    double z;

    friend std::istream& operator>>(std::istream& in, XYZCoordinate& xyz) {
        in >> xyz.x >> xyz.y >> xyz.z;
        return in;
    }
};