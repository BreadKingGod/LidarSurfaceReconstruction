#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <locale>
#include <limits>
#include <algorithm>

#include "Coordinates.hpp"

class ReadCoords
{
public:

	static void read() {
        std::ifstream in("L1_S5.xyz");
        Coordinates c;
        in >> c;
        std::cout << c;
	}
};