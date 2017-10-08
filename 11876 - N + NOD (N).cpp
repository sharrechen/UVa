#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void) {
    int T, A, B, n;
    vector<int> seq(64725);
    seq[0] = 1;
    for (int i = 1; i < 64725; ++i) {
        n = 0;
        for (int k = 1; k <= sqrt(seq[i - 1]); ++k) {
            if (seq[i - 1] % k == 0) {
                n++;
                if (k * k != seq[i - 1]) {
                    n++;
                }
            }
        }
        seq[i] = seq[i - 1] + n;
    }

    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> A >> B;
        vector<int>::iterator low = lower_bound(seq.begin(), seq.end(), A);
        vector<int>::iterator up = upper_bound(seq.begin(), seq.end(), B);
        cout << "Case " << t << ": " << up - low << endl;
    }

    return 0;
}
