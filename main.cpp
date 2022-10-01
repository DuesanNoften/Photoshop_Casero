//
// Created by kevin on 23/09/22.
//

#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main(){

    ImageProcessing test = ImageProcessing("G", "Prueba.jpeg",0.6);

    //prueba.filterType();
    //prueba.imgConfirmation();

    //Unit Testing
    ASSERT
    test.grayScale();
    test.gaussianBlur();
    test.gammaCorrection();
    test.brightControl();




    return 0;
}
