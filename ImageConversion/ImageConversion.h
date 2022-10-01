//
// Created by duesan on 01/10/22.
//

#ifndef PHOTOSHOP_CASERO_IMAGECONVERSION_H
#define PHOTOSHOP_CASERO_IMAGECONVERSION_H
#include "string"

using namespace std;

class ImageToBin{
public:
    string bin;
    ImageToBin(string imageName);

    void convertToBin();
    string getBin();
};

class BinToImage{
public:
    string result;
    BinToImage();

    void convertToImage();
    string getImage();
};

#endif //PHOTOSHOP_CASERO_IMAGECONVERSION_H
