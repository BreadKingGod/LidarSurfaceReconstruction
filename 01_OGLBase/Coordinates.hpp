#pragma once

#include <istream>
#include <vector>

#include "XYZCoordinate.hpp"


class Coordinates
{
    std::vector<XYZCoordinate> values;

public:

    friend std::ostream& operator<<(std::ostream& out, const Coordinates& c) {

        out << c.values.size() << " points\n";
        for (int i = 0; i < c.values.size(); i++) {
            out << "x: " << c.values[i].x << " y: " << c.values[i].y << " z: " << c.values[i].z << " \n";
        }

        return out;
    }

    friend std::istream& operator>>(std::istream& in, Coordinates& c) {

        XYZCoordinate xyz;

        while (in >> xyz) {
            c.values.push_back(xyz);
        }

        return in;
    }
};