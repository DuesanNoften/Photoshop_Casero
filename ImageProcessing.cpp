//
// Created by kevin on 19/09/22.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "ImageProcessing.h"

using namespace cv;
using namespace std;


//Class Constructor
ImageProcessing::ImageProcessing(string clientType, string path, float variation){
    type = clientType;
    img = imread(path);
    possibleVariation = variation;

}
//Method in charge of distinguishing the filter that has to be done.
int ImageProcessing::filterType(){
    if(type == "G"){
        gaussianBlur();
    }
    else if(type == "E"){
        grayScale();
    }
    else if(type == "B"){
        brightControl();
    }
    else if(type == "C"){
        gammaCorrection();
    }
    else{
        return -1;
    }
    return 0;
}
int ImageProcessing::gaussianBlur() {
    GaussianBlur(img,resultImg,Size(7,7),5,0);
}

int ImageProcessing::grayScale() { //
    cvtColor(img,resultImg,COLOR_BGR2GRAY);
}

int ImageProcessing::gammaCorrection() {

    float gamma = 1/possibleVariation;
    Mat table(1, 256, CV_8U);
    uchar *p = table.ptr();
    for (int i = 0; i < 256; ++i) {
        p[i] = (uchar) (pow(i / 255.0, gamma) * 255);
    }

    LUT(img, table, resultImg);
}


int ImageProcessing::brightControl() {
    img.convertTo(resultImg, -1, 1, possibleVariation);
}

// Test method to see the images
void ImageProcessing::imgConfirmation() {
    imshow("Original img",img);
    imshow("Filter img",resultImg);
    waitKey(0);
}

