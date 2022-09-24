//
// Created by kevin on 19/09/22.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class ImageProcessing{
private:
    char type;
    Mat img,resultImg;
    float possibleGamma,possibleBright;



public:
    ImageProcessing(char,string);

    int filterType();
    int gaussianBlur();
    int grayScale();
    int gammaCorrection();
    int brightControl();
    void imgConfirmation();

};
//Constructor de Clase
ImageProcessing::ImageProcessing(char _type,string path){
    type = _type;
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
        return -1;
    }
    return 0;
}
// Cambiar valores para que sean los enviados.
int ImageProcessing::gaussianBlur() {
    GaussianBlur(img,resultImg,Size(7,7),5,0);
    return 0;
}
// No necesita pasar nada
int ImageProcessing::grayScale() { //
    cvtColor(img,resultImg,COLOR_BGR2GRAY);
    return 0;
}

int ImageProcessing::gammaCorrection() {

    float gamma = 1/possibleGamma;

    Mat table (1, 256, CV_8U);
    uchar *p = table.ptr();
    for (int i = 0; i<256;++i){
        p[i] = (uchar) (pow(i / 255,gamma)*255);
    }
    LUT(img,table,resultImg);
    return 0;
}

int ImageProcessing::brightControl() {
    img.convertTo(resultImg, -1, -1, possibleBright);
    return 0;
}



// Metodo de prueba para ver las imagenes
void ImageProcessing::imgConfirmation() {
    imshow("Original img",img);
    imshow("Filter img",resultImg);
    waitKey(0);
}

