#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    unsigned int N;
    while (cin >> N) {
        vector<string> filenames(N);
        int maxLen = 0;
        for (size_t i = 0; i < N; ++i) {
            cin >> filenames[i];
            maxLen = max((int)filenames[i].length(), maxLen);
        }
        sort(filenames.begin(), filenames.end());
        int nc = 62 / (maxLen + 2); // number of column
        int H = ceil(N / (double)nc); // column height
        cout << "------------------------------------------------------------" << endl;
        for (int r = 0; r < H; ++r) {
            for (int c = r; c < N; c += H) {
                cout << setw(c + H < N ? maxLen + 2 : maxLen)
                     << left << filenames[c];
            }
            cout << endl;
        }
    }
    return 0;
}
