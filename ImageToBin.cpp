//
// Created by duesan on 22/09/22.
//
#include <fstream>
#include <iostream>
#include "cstring"
using namespace std;

void ImageToBin(string imageName){
    try {
        remove("bin_image_data.txt");
    }
    catch (bool) {

    }
    ifstream image(imageName, ios::in | ios::binary);
    ofstream binary("bin_image_data.txt", ios::out | ios::app);
    char contain;
    while (!image.eof()){
        contain=image.get();
        binary.put(contain);
    }
    image.close();
    binary.close();
}