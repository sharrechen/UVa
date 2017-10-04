#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q, T = 1;

    while (cin >> n >> q, n && q) {
        vector<int> marbles(n);
        for (size_t i = 0; i < n; ++i) {
            cin >> marbles[i];
        }
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << T++ << ":" << endl;
        while (q--) {
            cin >> n;
            vector<int>::iterator low = lower_bound(marbles.begin(), marbles.end(), n);
            if (n == *low) {
                cout << n << " found at " << (low - marbles.begin() + 1) << endl;
            } else {
                cout << n << " not found" << endl;
            }
        }
    }

  return 0;
}
