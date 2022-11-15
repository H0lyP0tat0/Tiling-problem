//
// Created by Honza Fojtík on 15.11.2022.
//

#include "TextReader.h"

TextReader::TextReader(string source) {
    this->source = source;
}

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


void TextReader::printFile() {
    for (int i = 0; i < this->a.size(); i++) {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }
}

vector<string> TextReader::getA() {
    return this->a;
}

vector<string> TextReader::getB() {
    return this->b;
}

vector<string> TextReader::getC() {
    return this->c;
}



