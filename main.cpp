//
// Created by kevin on 23/09/22.
//

#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main(){

    ImageProcessing prueba = ImageProcessing("G", "Prueba.jpeg",0.6);
    prueba.filterType();
    prueba.imgConfirmation();

    return 0;
}
