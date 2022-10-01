//
// Created by duesan on 22/09/22.
//
#include <fstream>
#include <iostream>
#include "unistd.h"
#include "ImageConversion.h"

using namespace std;

// This code
BinToImage::BinToImage() {
    string result;
}

void BinToImage::convertToImage() {
    try{
        remove("Result.jpg");
    }
    catch (bool){

    }
    ofstream image("Result.jpg", ios::out | ios::app);
    ifstream binary("bin_image_data.txt", ios::in | ios::app | ios:: binary);
    char contain;
    while (!binary.eof()) {
        contain = binary.get();
        image.put(contain);
    }
    image.close();
    binary.close();
    this->result=get_current_dir_name();
    this->result+="Result.jpg";
}

string BinToImage::getImage() {
    return this->result;
}

