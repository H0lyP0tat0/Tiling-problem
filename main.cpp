#include <iostream>
#include "TextReader.h"

using namespace std;

void printSolution(int a, int b, int c) {
    cout << a << " x " << b << " - " << c << endl;
}

int countEven(int n) {

}

int tiling(const vector<string>& a, const vector<string>& b) {
    int a_dim, b_dim, result;


    for (int i = 0; i < a.size(); i++) {
        a_dim = stoi(a[i]);
        b_dim = stoi(b[i]);

        result = 1;
        if (a_dim % 2 == 1 && b_dim % 2 == 1) {
            result = 0;
            printSolution(a_dim, b_dim, result);
        }

        if (a_dim == b_dim) {
            result = countEven(a_dim);
            printSolution(a_dim, b_dim, result);
        }
    }

    return 1;
}

int main() {
    //int n = 2;
    //cout << countWays(n);

    TextReader tr("in.txt");
    tr.loadFile();

    //tr.printFile();

    tiling(tr.getA(), tr.getB());

    return 0;
}
