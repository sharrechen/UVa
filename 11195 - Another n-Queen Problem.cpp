#include <iostream>
#include <vector>
using namespace std;

void queensChess(vector<int> & board, int & rw, int & ld, int & rd, int & sol, int c) {
    if (c == board.size()) {
        ++sol;
        return;
    }

    for (int r = 0; r < board.size(); ++r) {
        if (board[c] & (1 << r) && !(rw & 1 << r) && !(ld & (1 << (r - c + board.size() - 1))) && !(rd & (1 << (r + c))) ) {
            rw |= 1 << r; // record if queen place at this row
            ld |= 1 << (r - c + board.size() - 1); // record queen use this left diagonal
            rd |= 1 << (r + c);
            queensChess(board, rw, ld, rd, sol, c + 1);
            rw ^= 1 << r; // set back for choose another row to place queen
            ld ^= 1 << (r - c + board.size() - 1);
            rd ^= 1 << (r + c);
        }
    }
}

int main(void) {
    int n, t = 1;

    while (cin >> n, n) {
        vector<int> board(n, (1 << n) - 1);
        int rw = 0, ld = 0, rd = 0, sol = 0;
        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < n; ++c) {
                char s;
                cin >> s;
                if (s == '*') {
                    board[c] ^= (1 << r);
                }
            }
        }

        queensChess(board, rw, ld, rd, sol, 0);
        cout << "Case " << t++ << ": " << sol << endl;
    }

    return 0;
}