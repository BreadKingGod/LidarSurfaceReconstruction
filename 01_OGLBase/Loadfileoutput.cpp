#include "Loadfileoutput.h"

Loadfileoutput Loadfile(std::string filename)
{
    std::ifstream in(filename);
    if (!in) {
        std::cout << "Cannot open input file.\n";
        exit(EXIT_FAILURE);
    }

    std::string str;
    bool isfirst = true;
    int xmin, xmax, ymin, ymax;
    std::vector<XYZCoordinate> file = std::vector<XYZCoordinate>();
    while (std::getline(in, str)) //potential cause of bottleneck
    {
        if (str[0] == '#') //.skipping the .txt file header
            continue;
        std::vector<std::string> v = std::vector<std::string>();

        boost::split(v, str, boost::is_any_of(" ,"));

        std::string xstr = v[0];
        std::string ystr = v[1];
        std::string zstr = v[2];
        int xint, yint;
        float x, y, z;

        std::stringstream(v[0]) >> x;
        xint = (int)round(x);

        std::stringstream(v[1]) >> y;
        yint = (int)round(y);

        std::stringstream(v[2]) >> z;

        XYZCoordinate temp = XYZCoordinate(xint, yint, z);
        file.push_back(temp);

        //get bounds
        if (isfirst)
        {
            xmin = xint;
            xmax = xint;
            ymin = yint;
            ymax = yint;
            isfirst = false;
        }
        else
        {
            //set xmin/max for scaling
            if (xint > xmax)
                xmax = xint;
            else if (xint < xmin)
                xmin = xint;
            //set ymin/max for scaling
            if (yint > ymax)
                ymax = yint;
            else if (yint < ymin)
                ymin = yint;
        }
    }
    Loadfileoutput output = Loadfileoutput(xmin, xmax, ymin, ymax, file);

    return output;
}