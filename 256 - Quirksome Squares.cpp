#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

void quirksome(vector<vector<int> > & quirksome_squares, int square, int num) {
    int a = square / (int) pow(10.0, num >> 1);
    int b = square % (int) pow(10.0, num >> 1);
    if ((a + b) * (a + b) == square) {
        quirksome_squares[num].push_back(square);
    }
    return;
}

int main(void) {
    vector<vector<int> > quirksome_squares(10, vector<int>(2));
    int i;

    // pre-calculate, since input only taken from 2, 4, 6, 8
    for (i = 2; i <= 8; i += 2) {
        quirksome_squares[i][0] = 0;
        quirksome_squares[i][1] = 1;
    }

    for (i = 2; i < 10000; ++i) {
        int square = i * i;
        if (square < 100) {
            quirksome(quirksome_squares, square, 2);
        } else if (square < 10000) {
            quirksome(quirksome_squares, square, 4);
        } else if (square < 1000000) {
            quirksome(quirksome_squares, square, 6);
        } else if (square < 100000000) {
            quirksome(quirksome_squares, square, 8);
        }
    }

    while (cin >> i) {
        for (size_t j = 0; j < quirksome_squares[i].size(); ++j) {
            cout << setw(i) << setfill('0') << quirksome_squares[i][j] << endl;
        }
    }

    return 0;
}