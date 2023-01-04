#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <locale>
#include <limits>
#include <algorithm>

#include "Coordinates.hpp"
#include <windows.h>
#include <gl/GL.h>
#include <gl/glew.h>
#include <SDL_opengl.h>

class Coords
{
public:

	static Coordinates read()
    {
        std::ifstream in("points.xyz");
        Coordinates c;
        in >> c;

        return c;
	}

    static void print(Coordinates c)
    {
        std::cout << c;
    }

    static void draw(Coordinates c)
    {
        glBegin(GL_POINTS);

        for (int i = 0; i < c.values.size(); i++)
        {
            glVertex3f(c.values[i].x, c.values[i].y, c.values[i].z);
        }

        glEnd();
    }
};