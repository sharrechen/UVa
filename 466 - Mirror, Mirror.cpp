#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > rotate90(vector<vector<char> > & origin, int dimension) {
    vector<vector<char> > result(dimension, vector<char>(dimension));
    for (int r = 0; r < dimension; ++r) {
        for (int c = 0; c < dimension; ++c) {
            result[c][(dimension - 1) - r] = origin[r][c];
        }
    }
    return result;
}

vector<vector<char> > reflectVertical(vector<vector<char> > & origin, int dimension) {
    for (int r = 0; r < dimension >> 1; ++r) {
        for (int c = 0; c < dimension; ++c) {
            swap(origin[r][c], origin[dimension - r - 1][c]);
        }
    }
    return origin;
}

int checkRotate(vector<vector<char> > & origin, vector<vector<char> > & result, int & dimension) {
    for (int r = 1; r <= 4; ++r) {
        if ((origin = rotate90(origin, dimension)) == result) {
            return r;
        }
    }

    return 0;
}

int main() {
    int dimension, nCase = 1;
    while (cin >> dimension) {
        vector<vector<char> > origin(dimension, vector<char>(dimension));
        vector<vector<char> > result(dimension, vector<char>(dimension));
        for (int r = 0; r < dimension; ++r) {
            for (int c = 0; c < dimension; ++c) {
                cin >> origin[r][c];
            }
            getchar();
            for (int c = 0; c < dimension; ++c) {
                cin >> result[r][c];
            }
        }
        int r = 0;
        cout << "Pattern " << nCase++ << " was ";
        if (origin == result) {
            cout << "preserved." << endl;
            continue;
        }

        if ((r = checkRotate(origin, result, dimension))) {
            cout << "rotated " << 90 * r << " degrees." << endl;
            continue;
        }

        if ((origin = reflectVertical(origin, dimension)) == result) {
            cout << "reflected vertically." << endl;
            continue;
        }

        if ((r = checkRotate(origin, result, dimension))) {
            cout << "reflected vertically and rotated " << 90 * r << " degrees." << endl;
            continue;
        }
        cout << "improperly transformed." << endl;
    }

    return 0;
}
