//
// Created by kevin on 23/09/22.
//

#ifndef PHOTOSHOP_CASERO_IMAGEPROCESSING_H
#define PHOTOSHOP_CASERO_IMAGEPROCESSING_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class ImageProcessing{
private:

    string type;
    Mat img,resultImg;
    float possibleVariation;



public:
    ImageProcessing(string clientType, string path, float variation);

    int filterType();

    int gaussianBlur();
    int grayScale();
    int gammaCorrection();
    int brightControl();

    void imgConfirmation();


};

#endif //PHOTOSHOP_CASERO_IMAGEPROCESSING_H
