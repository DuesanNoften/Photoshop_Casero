//
// Created by kevin on 19/09/22.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class ImageProcessing{
private:
    char type;
    Mat img,resultImg;


public:
    ImageProcessing(char,string);

    char filterType(char);
    int gaussianBlur();
    int grayScale();
    int gammaCorrection();
    int brightControl();

};

ImageProcessing::ImageProcessing(char _type,string path){
    type = _type;
    Mat img = imread(path);


}

char ImageProcessing::filterType(char filter){
    if(filter == 'G'){
        cout <<"Filtro Gaussian";
        gaussianBlur();
    }
    else if(filter == 'E'){
        cout <<"Filtro Escala de grises";
        grayScale();
    }
    else if(filter == 'B'){
        cout <<"Filtro Brillo";
        brightControl();
    }
    else if(filter == 'C'){
        cout <<"Filtro Correcion gamma";
        gammaCorrection();
    }
    else{
        cout << "Meh, no funca";
    }
    return 0;
}

int ImageProcessing::gaussianBlur() {
    GaussianBlur(img,resultImg,Size(7,7),5,0); // Cambiar valores para que sean los enviados.
    return 0;
}

int ImageProcessing::grayScale() {
    cvtColor(img,resultImg,COLOR_BGR2GRAY);
    return 0;
}

int ImageProcessing::gammaCorrection() {
    return 0;
}

int ImageProcessing::brightControl() {
    return 0;
}