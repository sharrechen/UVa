#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T, N;
    char _c;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> _c >> _c >> N;
        bool isSym = true;
        vector<vector<long long> > M(N, vector<long long>(N));
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                cin >> M[r][c];
                if (M[r][c] < 0) {
                    isSym = false;
                }
            }
        }

        for (int r = 0; r < N - 1; ++r) {
            for (int c = r; c < N; ++c) {
                if (M[r][c] != M[N - r - 1][N - c - 1]) {
                    isSym = false;
                    break;
                }
            }
        }
        cout << "Test #" << t << ": "
             << (isSym ? "Symmetric." : "Non-symmetric.") << endl;
    }
    return 0;
}
