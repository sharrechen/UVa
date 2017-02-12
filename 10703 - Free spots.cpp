#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    bool spots[500][500];
    unsigned int W, H, N, X1, Y1, X2, Y2;

    while (cin >> W >> H >> N, W) {
        while (N--) {
            cin >> X1 >> Y1 >> X2 >> Y2;
            for (int y = min(Y1, Y2) - 1; y < max(Y1, Y2); ++y) {
                for (int x = min(X1, X2) - 1; x < max(X1, X2); ++x) {
                    spots[y][x] = true;
                }
            }
        }
        int nEmpty = W * H; // number of emptySpots
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (spots[y][x]) {
                    --nEmpty;
                    spots[y][x] = false;
                }
            }
        }
        if (nEmpty > 1) {
            cout << "There are " << nEmpty << " empty spots." << endl;
        } else if (nEmpty == 1) {
            cout << "There is one empty spot." << endl;
        } else {
            cout << "There is no empty spots." << endl;
        }
    }
    return 0;
}
