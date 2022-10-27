#pragma once

#include <iostream>
#include "XYZCoordinate.h"
#include <vector>

class Loadfileoutput
{
public:
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    std::vector<XYZCoordinate> values;

    Loadfileoutput(int xmn, int xmx, int ymn, int ymx, std::vector<XYZCoordinate> val) {
        xmin = xmn;
        xmax = xmx;
        ymin = ymn;
        ymax = ymx;
        values = val;
    }
};

