
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(void) {
    int n, m;

    while (cin >> n >> m, n) {
        int a, b, cnt = 0;
        vector<int> seats(n);
        vector<vector<int> > limits(m, vector<int>(3)); // social constraints
        for (int i = 0; i < n; ++i) seats[i] = i;
        for (size_t i = 0; i < m; ++i) {
            cin >> limits[i][0] >> limits[i][1] >> limits[i][2];
        }
        do {
            bool pass = true;
            for (size_t i = 0; i < m && pass; ++i) { // check if this seat arrangement pass all social constraint
                a = find(seats.begin(), seats.end(), limits[i][0]) - seats.begin();
                b = find(seats.begin(), seats.end(), limits[i][1]) - seats.begin();
                if (limits[i][2] < 0) {
                    pass =  abs(a - b) >= abs(limits[i][2]) ? true : false;
                } else {
                    pass =  abs(a - b) <= abs(limits[i][2]) ? true : false;
                }
            }
            if (pass) ++cnt;
        } while (next_permutation(seats.begin(), seats.end()));
        cout << cnt << endl;
    }

    return 0;
}