#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int t, r;

    cin >> t;
    while (t--) {
        cin >> r;
        vector<int> streets(r);
        for (size_t i = 0; i < r; ++i) {
            cin >> streets[i];
        }
        sort(streets.begin(), streets.end());
        int sum = 0, middle = streets[streets.size() >> 1];
        for (size_t s = 0; s < streets.size(); ++s) {
            sum += abs(streets[s] - middle);
        }
        cout << sum << endl;
    }

    return 0;
}