#pragma once

#include <istream>

struct XYZCoordinate {
    int x;
    int y;
    float z;

    friend std::istream& operator>>(std::istream& in, XYZCoordinate& xyz) {
        float a, b;
        in >> a >> b >> xyz.z;
        xyz.x = std::rint(a);
        xyz.y = std::rint(b);
        return in;
    }
};