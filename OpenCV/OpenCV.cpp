#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <direct.h>
#define GetCurrentDir _getcwd
#include <iostream>
using namespace cv;

std::string get_current_dir() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}

int main()
{
    std::cout << get_current_dir() << std::endl;
    std::string image_path = "starry_night2.jpg";
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        imwrite("starry_night.png", img);
    }
    return 0;
}