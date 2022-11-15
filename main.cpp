#include <iostream>
#include <cmath>
#include "TextReader.h"

using namespace std;

/// @brief printSolution is a function that prints the final result with the dimensions of the room int console
/// @param a, b, c, results are numbers that will be displayed
void printSolution(int a, int b, int c, int result) {
    cout << a << " x " << b << " - " << "expected result: " << c << " my result: " << result << endl;
}

// Fibonacci sequence https://oeis.org/A000045
/// @brief fib is a function that returns the n-th fibonacci number
/// @param n is the given number for the fibonacci sequence
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

/// @brief tiling is a function that calculates all the possible combinations for tile placement into a room
/// @param a, b, c are the vectors used for the calculations
void tiling(const vector<string>& a, const vector<string>& b, const vector<string>& c) {
    // declaring variables that I will use
    int a_dim, b_dim, c_num, i, j, k;
    double result;

    // for every record in the vectors a, b, c
    for (i = 0; i < a.size(); i++) {
        // we get the values from the vectors
        // a_dim and b_dim are the dimensions, c_num is the expected result
        a_dim = stoi(a[i]);
        b_dim = stoi(b[i]);
        c_num = stoi(c[i]);
        result = 1;


        // SPECIAL CASES
        // If the dimensions are less than 2 x 2 or if a and b are both odd the answer is always 0
        if ((a_dim < 2 && b_dim < 2) || (a_dim % 2 == 1 && b_dim % 2 == 1)) {
            result = 0;
        // If the dimension is 2 x b (a x 2) the result is a number from the Fibonacci sequence
        } else if ((a_dim == 2 && b_dim != 2) || (a_dim != 2 && b_dim == 2)) {
            if (a_dim == 2) {
                result = fib(b_dim + 1);
            } else {
                result = fib(a_dim + 1);
            }
        // If a == b and a is even the result is a number from this sequence https://oeis.org/A004003
        } else if (a_dim == b_dim && a_dim % 2 == 0) {
            // Product(j)[Product(k)[ equation ]];
            // equation -> [4 * cos((j * Pi) / (2 * n + 1))^2 + 4 * cos((k * Pi) / (2 * n + 1))^2] where j={1..n}, k={1..n} and n=a_dim/2
            int n = a_dim / 2;
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= n; k++) {
                    result *= (4 * pow(cos((M_PI * j) / (2 * n + 1)), 2) + 4 * pow(cos((M_PI * k) / (2 * n + 1)), 2));
                }
            }
        // Else we use the function calculated by Temperley & Fisher (1961) and Kasteleyn (1961)
        // https://en.wikipedia.org/wiki/Domino_tiling#Counting_tilings_of_regions
        } else {
            for (j = 1; j <= a_dim / 2; j++) {
                for (k = 1; k <= b_dim / 2; k++) {
                    result *= (4 * pow(cos((M_PI * j) / (a_dim + 1)), 2)) + (4 * pow(cos((M_PI * k) / (b_dim + 1)), 2));
                }
            }
        }

        // printing the solution
        printSolution(a_dim, b_dim, c_num, result);
    }
}

// https://en.wikipedia.org/wiki/Domino_tiling
/// @brief main cycle of the program
int main() {
    // loading the txt file
    TextReader tr("in.txt");

    // performing the calculations of the tiling problem
    tiling(tr.getA(), tr.getB(), tr.getC());

    return 0;
}
