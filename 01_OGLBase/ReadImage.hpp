#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <direct.h>
#include <iostream>

class ReadImage
{
public:

    static void read() {

        std::string image_path = "starry_night.png";
        cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

        if (img.empty())
        {
            std::cout << "Could not read the image: " << image_path << std::endl;
        }
        else
        {
            imshow("Display window", img);
            int k = cv::waitKey(0); // Wait for a keystroke in the window

            if (k == 's')
            {
                imwrite("starry_night.png", img);
            }
        }
    }
};