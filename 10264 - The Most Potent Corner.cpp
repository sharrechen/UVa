#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
* Ex. N = 3, each corner's neighbouring corners:
* 0 -> 1, 2, 4
* 1 -> 0, 3, 5
* 2 -> 0, 3, 6
* 3 -> 1, 2, 7
* 4 -> 0, 5, 6
* 5 -> 1, 4, 7
* 6 -> 2, 4, 7
* 7 -> 3, 5, 6
*/
int main(void) {
    unsigned int N;
    while (cin >> N) {
        int corners = 1 << N; // total corners for N-dimensional
        vector<int> weights(corners);
        vector<int> potencies(corners);
        for (size_t i = 0; i < corners; ++i) {
            cin >> weights[i];
        }
        for (size_t i = 0; i < corners; ++i) {
            for (size_t n = 0; n < N; ++n) { // add all neightbors
                potencies[i] += weights[i ^ (1 << n)];
            }
        }
        int max_sum = 0;
        for (size_t i = 0; i < corners; ++i) {
            for (size_t n = 0; n < N; ++n) {
                max_sum = max(max_sum, potencies[i] + potencies[i ^ (1 << n)]);
            }
        }
        cout << max_sum << endl;
    }
    return 0;
}
