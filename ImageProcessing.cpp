//
// Created by kevin on 19/09/22.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

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
        return 0;
    }
    else if(type == "E"){
        grayScale();
        return 0;
    }
    else if(type == "B"){
        brightControl();
        return 0;
    }
    else if(type == "C"){
        gammaCorrection();
        return 0;
    }
    else{
        return -1;
    }

}
int ImageProcessing::gaussianBlur() {
    if (img.empty()) {
        return -1;
    }
    GaussianBlur(img,resultImg,Size(7,7),5,0);
    remove("ImagenFiltro.jpg");
    imwrite("ImagenFiltro.jpg",resultImg);

    return 0;
}

int ImageProcessing::grayScale() {
    if (img.empty()) {
        return -1;
    }
    cvtColor(img,resultImg,COLOR_BGR2GRAY);
    remove("ImagenFiltro.jpg");
    imwrite("ImagenFiltro.jpg",resultImg);
    return 0;
}

int ImageProcessing::gammaCorrection() {
    if (img.empty()) {
        return -1;
    }

    float gamma = 1/possibleVariation;
    Mat table(1, 256, CV_8U);
    uchar *p = table.ptr();
    for (int i = 0; i < 256; ++i) {
        p[i] = (uchar) (pow(i / 255.0, gamma) * 255);
    }

    LUT(img, table, resultImg);
    remove("ImagenFiltro.jpg");
    imwrite("ImagenFiltro.jpg",resultImg);

    return 0;
}


int ImageProcessing::brightControl() {
    if (img.empty()) {
        return -1;
    }
    img.convertTo(resultImg, -1, 1, possibleVariation);
    remove("ImagenFiltro.jpg");
    imwrite("ImagenFiltro.jpg",resultImg);
    return 0;
}

// Test method to see the images
void ImageProcessing::imgConfirmation() {
    imshow("Original img",img);
    imshow("Filter img",resultImg);
    waitKey(0);
}

