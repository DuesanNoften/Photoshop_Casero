//
// Created by duesan on 22/09/22.
//
#include <fstream>
#include <iostream>
#include "cstring"
using namespace std;

int main(){
    try {
        remove("bin_image_data.txt");
    }
    catch (bool) {

    }
    string name;
    cout<<"Ingrese nombre de la imagen"; cin>>name;
    ifstream image(name, ios::in | ios::binary);
    ofstream binary("bin_image_data.txt", ios::out | ios::app);
    char contain;
    while (!image.eof()){
        contain=image.get();
        binary.put(contain);
    }
    image.close();
    binary.close();
    return 0;
}