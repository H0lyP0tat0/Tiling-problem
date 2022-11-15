//
// Created by Honza Fojtík on 15.11.2022.
//

#include "TextReader.h"

/// @brief Constructor for my TextReader class
/// @params source is the name of the file thats being loaded
TextReader::TextReader(string source) {
    this->source = source;
    loadFile();
}

/// @brief loadFile is a function that scans the contents of a txt file
void TextReader::loadFile() {
    ifstream file;
    int counter = 0;

    file.open(this->source, ios::in);

    if (file.is_open()) {
        string line;

        while (getline(file, line, '\n')) {
            this->lines += line + " ";
        }
    }

    file.close();
    split();
}

/// @brief split is a function that splits the numbers into 3 vectors, a - for the first dimension, b - for the second dimension, c - for the expected result
void TextReader::split() {
    stringstream ss(lines);
    string s;
    int counter = 0;

    while (std::getline(ss, s, ' ')) {
        switch (counter % 3) {
            case 0:
                this->a.push_back(s);
                break;
            case 1:
                this->b.push_back(s);
                break;
            case 2:
                this->c.push_back(s);
                break;
        }

        counter++;
    }
}


/// @brief printFile is a function that prints the contents of the vectors a, b, c. It shows the layout of the txt file
void TextReader::printFile() {
    for (int i = 0; i < this->a.size(); i++) {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }
}

/// @brief getA is a getter for vector a
vector<string> TextReader::getA() {
    return this->a;
}

/// @brief getB is a getter for vector b
vector<string> TextReader::getB() {
    return this->b;
}

/// @brief getCis a getter for vector c
vector<string> TextReader::getC() {
    return this->c;
}



