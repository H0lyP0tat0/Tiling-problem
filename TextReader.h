//
// Created by Honza Fojtík on 15.11.2022.
//

#ifndef PROJEKT_TEXTREADER_H
#define PROJEKT_TEXTREADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class TextReader {

private:
    string source;
    string lines;

    vector<string> a;
    vector<string> b;
    vector<string> c;

public:
    TextReader(string source);

    void split();
    void loadFile();
    void printFile();

    vector<string> getA();
    vector<string> getB();
    vector<string> getC();
};


#endif //PROJEKT_TEXTREADER_H
