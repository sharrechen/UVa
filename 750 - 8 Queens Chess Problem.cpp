#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

bool place(vector<int> & row, int R, int C) {
    for (int c = 0; c < C; ++c) {
        if (row[c] == R || abs(row[c] - R) == abs(c - C)) {
            return false;
        } 
    }
    return true;
}

void queensChess(vector<int> & row, int & l, int & qr, int & qc, int C) {
    if (C == row.size() && row[qc] == qr) {
        cout << setw(2) << l++ << "      " << row[0];
        for (size_t c = 1; c < row.size(); ++c) {
            cout << " " << row[c];
        }
        cout << endl;
    }
    for (int r = 1; r <= row.size(); ++r) {
        if (place(row, r, C)) {
            row[C] = r;
            queensChess(row, l, qr, qc, C + 1);
        }
    }
}

int main(void) {
    int n, qr, qc;

    cin >> n;
    getchar();
    while (n--) {
        getchar();
        vector<int> row(8);
        int l = 1;
        cin >> qr >> qc;

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl; 
        queensChess(row, l, qr, --qc, 0);

        if (n) cout << endl;
    }

    return 0;
}