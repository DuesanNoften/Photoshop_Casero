//
// Created by kevin on 23/09/22.
//
#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main(){
    cout << "Hola mundo";
    ImageProcessing prueba = ImageProcessing('C', "Prueba.jpeg");
    prueba.filterType();
    prueba.imgConfirmation();
    return 0;
}