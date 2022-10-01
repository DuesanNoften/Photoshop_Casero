//
// Created by duesan on 01/10/22.
//

#include "filesystem"
#include "vector"
#include "iostream"
#include "fstream"

using namespace std;

//Function that returns a string containing a line from a txt file.
//E: string with the file path
//S: string with the text contents
vector<string> sender(string filePath){
    vector<string> lines;
    string actualLine;
    ifstream file(filePath, ifstream::binary);
    /*if (!file.is_open()) {
        cerr << "Could not open the file - '"
             << filePath << "'" << endl;
    }*/
    while(getline(file, actualLine)){
        lines.push_back(actualLine);
    }
}