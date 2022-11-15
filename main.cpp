#include <iostream>
#include <cmath>
#include "TextReader.h"

using namespace std;

void printSolution(int a, int b, int c, int result) {
    cout << a << " x " << b << " - " << "expected result: " << c << " my result: " << result << endl;
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int count(int n, int m) {
    return 100;
}

int countSame(int n) {
    return 10;
}

int countEven(int n, int m) {
    return 20;
}

int tiling(const vector<string>& a, const vector<string>& b, const vector<string>& c) {
    int a_dim, b_dim, c_dim, j, k, i;
    double result;

    for (i = 0; i < a.size(); i++) {
        a_dim = stoi(a[i]);
        b_dim = stoi(b[i]);
        c_dim = stoi(c[i]);

        result = 1;

        // If the dimension in less than 2 x 2 or if a and b are both odd the answer is always 0
        if ((a_dim < 2 && b_dim < 2) || (a_dim % 2 == 1 && b_dim % 2 == 1)) {
            result = 0;
        // If the dimension is 2 x b (a x 2) the result is reduced to the Fibonacci sequence
        } else if ((a_dim == 2 && b_dim != 2) || (a_dim != 2 && b_dim == 2)) {
            if (a_dim == 2) {
                result = fib(b_dim + 1);
            } else {
                result = fib(a_dim + 1);
            }
        // If a == b and a is even the result is reduced to this sequence https://oeis.org/A004003
        } else if (a_dim == b_dim && a_dim % 2 == 0) {
            // [4 * cos(j * Pi / (2 * n + 1))^2 + 4 * cos(k * Pi / (2 * n + 1))^2] where j={1..n}, k={1..n}


            // DOESNT WORK YET
            for (j = 1; j <= a_dim; j++) {
                for (k = 1; k <= a_dim; k++) {
                    // [4*cos(j*Pi/(2*n+1))^2 + 4*cos(k*Pi/(2*n+1))^2]
                    result *= (4 * pow(cos((M_PI * j) / (2 * a_dim + 1)), 2) + 4 * pow(cos((M_PI * k) / (2 * a_dim + 1)), 2));
                }
            }
        // Else we use the function by Temperley & Fisher (1961) and Kasteleyn (1961)
        // https://en.wikipedia.org/wiki/Domino_tiling#Counting_tilings_of_regions
        } else {
            for (j = 1; j <= a_dim / 2; j++) {
                for (k = 1; k <= b_dim / 2; k++) {
                    result *= (4 * pow(cos((M_PI * j) / (a_dim + 1)), 2)) + (4 * pow(cos((M_PI * k) / (b_dim + 1)), 2));
                }
            }
        }


//        } else if (a_dim == b_dim) {
//            result = countSame(a_dim);
//        } else if (a_dim % 2 == 0 && b_dim % 2 == 0) {
//            result = countEven(a_dim, b_dim);
//        } else {
//            result = count(a_dim, b_dim);
//        }

        printSolution(a_dim, b_dim, c_dim, result);
    }

    return 1;
}

int main() {
    //int n = 2;
    //cout << countWays(n);

    TextReader tr("in.txt");
    tr.loadFile();

    //tr.printFile();

    tiling(tr.getA(), tr.getB(), tr.getC());

    return 0;
}
