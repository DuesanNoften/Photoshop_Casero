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

//Constructor de Clase
ImageProcessing::ImageProcessing(char clientType, string path){
    type = clientType;
    img = imread(path);
}

int ImageProcessing::filterType(){
    if(type == 'G'){
        cout <<"Filtro Gaussian";
        gaussianBlur();
    }
    else if(type == 'E'){
        cout <<"Filtro Escala de grises";
        grayScale();
    }
    else if(type == 'B'){
        cout <<"Filtro Brillo";
        brightControl();
    }
    else if(type == 'C'){
        cout <<"Filtro Correcion gamma";
        gammaCorrection();
    }
    else{
        cout << "Meh, no funca";
    }
}
int ImageProcessing::gaussianBlur() {
    GaussianBlur(img,resultImg,Size(7,7),5,0);
}

int ImageProcessing::grayScale() { //
    cvtColor(img,resultImg,COLOR_BGR2GRAY);
}

int ImageProcessing::gammaCorrection() {

    float gamma = 1/possibleBright;
    Mat table(1, 256, CV_8U);
    uchar *p = table.ptr();
    for (int i = 0; i < 256; ++i) {
        p[i] = (uchar) (pow(i / 255.0, gamma) * 255);
    }

    LUT(img, table, resultImg);
}


int ImageProcessing::brightControl() {
    img.convertTo(resultImg, -1, 1, possibleBright);
}

// Metodo de prueba para ver las imagenes
void ImageProcessing::imgConfirmation() {
    imshow("Original img",img);
    imshow("Filter img",resultImg);
    waitKey(0);
}

