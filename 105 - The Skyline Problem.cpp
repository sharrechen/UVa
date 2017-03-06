#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int L, H, R, min_x = 10000, max_x = 0;
    vector<int> skyline(10001, 0); // skyline record

    while (cin >> L >> H >> R) {
        min_x = min(min_x, L);
        max_x = max(max_x, R);
        for (int x = L; x < R; ++x) {
            if (H > skyline[x]) {
                skyline[x] = H;
            }
        }
    }

    cout << min_x << " " << skyline[min_x];
    for (int x = min_x + 1; x <= max_x; ++x) {
        if (skyline[x] != skyline[x - 1]) {
            cout << " " << x << " " << skyline[x];
        }
    }
    cout << endl;

    return 0;
}