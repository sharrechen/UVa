#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    unsigned int dimension;
    while (cin >> dimension, dimension) {
        int checkR = 128;
        int checkC = 128;
        bool isCorrupt = false;
        vector<vector<int> > matrix(dimension, vector<int>(dimension));
        for (int r = 0; r < dimension; ++r) {
            int cSum = 0;
            for (int c = 0; c < dimension; ++c) {
                cin >> matrix[r][c];
                cSum += matrix[r][c];
            }
            if (!isCorrupt && (cSum & 1)) {
                if (checkR != 128) {
                    isCorrupt = true;
                    continue;
                }
                checkR = r;
            }
        }

        for (int c = 0; c < dimension; ++c) {
            int rSum = 0;
            for (int r = 0; r < dimension; ++r) {
                rSum += matrix[r][c];
            }
            if (!isCorrupt && (rSum & 1)) {
                if (checkC != 128) {
                    isCorrupt = true;
                    break;
                }
                checkC = c;
            }
        }
        if (isCorrupt) {
            cout << "Corrupt" << endl;
        } else if (checkR & 128) {
            cout << "OK" << endl;
        } else {
            cout << "Change bit (" << checkR + 1 << "," << checkC + 1 << ")" << endl;
        }
    }

    return 0;
}
