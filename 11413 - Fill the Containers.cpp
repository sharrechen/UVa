#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool fillContainersByCapacity(vector<int> & vessels, int nContainers, int capacity) {
    int m = 0;
    int c = capacity;
    for (int v = 0; v < vessels.size(); ++v) {
        if (vessels[v] > capacity) {
            return false;
        }

        if (vessels[v] > c) {
            m++;
            c = capacity;
            if (m == nContainers) {
                return false;
            }
        }
        c -= vessels[v];
    }
    return true;
}

int main(void) {
    int nVessels, nContainers, lo, hi, mid, ans;
    while (cin >> nVessels >> nContainers) {
        vector<int> vessels(nVessels);
        for (int c = 0; c < nVessels; ++c) {
            cin >> vessels[c];
        }

        // the capacity 1 ≤ c ≤ 1000000 of each vessel
        hi = 1000000000;
        lo = 1;
        for (int c = 1; c <= 32; ++c) {
            mid = (hi + lo) >> 1;
            if (fillContainersByCapacity(vessels, nContainers, mid)) {
                ans = mid;
                hi = mid;
            } else {
                lo = mid != lo ? mid : mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
