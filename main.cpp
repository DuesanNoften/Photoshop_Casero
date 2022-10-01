//
// Created by kevin on 23/09/22.
//

#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main(){

    ImageProcessing test = ImageProcessing("G", "Prueba.jpeg",0.6);

    test.filterType();
    //test.imgConfirmation();

    //Unit Testing

/*
    if(test.grayScale() == 0){
        cout << "funciona como fue esperado" << endl;
    }else{
        cout << "fallo inesperado" << endl;
    }

    if(test.gaussianBlur()== 0){
        cout << "funciona como fue esperado" << endl;
    }else{
        cout << "fallo inesperado" << endl;
    }

    if(test.gammaCorrection() == 0){
        cout << "funciona como fue esperado" << endl;
    }else{
        cout << "fallo inesperado" << endl;
    }

    if(test.brightControl() == 0){
        cout << "funciona como fue esperado" << endl;
    }else{
        cout << "fallo inesperado" << endl;
    }

    if(test.filterType() == -1){
        cout << "fallo esperado" << endl;
    }else{
        cout << "acierto inesperado" << endl;
    }
*/
    return 0;
}
