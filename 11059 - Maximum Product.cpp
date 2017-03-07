#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, t = 1;

    while (cin >> N) {
        vector<int> S(N);
        for (size_t i = 0; i < N; ++i) {
            cin >> S[i];
        }
        // maximum positive product involving consecutive terms of S
        long long max_prdt = 0;
        for (size_t i = 0; i < S.size(); ++i) {
            long long prdt = 1;
            for (size_t j = i; j < S.size() && S[j] != 0; ++j) {
                prdt *= S[j];
                max_prdt = max(max_prdt, prdt);
            }
        }
        cout << "Case #" << t++ << ": The maximum product is " << max_prdt << "." << endl << endl;
    }

    return 0;
}