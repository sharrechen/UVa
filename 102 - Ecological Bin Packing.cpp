#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(void) {
    int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    string color[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3;
        int total = b1 + g1 + c1 + b2 + g2 + c2 + b3 + g3 + c3;
        vector<int> moves(9, total);
        moves[0] -= b1 + c2 + g3;
        moves[1] -= b1 + g2 + c3;
        moves[2] -= c1 + b2 + g3;
        moves[3] -= c1 + g2 + b3;
        moves[4] -= g1 + b2 + c3;
        moves[5] -= g1 + c2 + b3;
        int min_index = min_element(moves.begin(), moves.end()) - moves.begin();
        cout << color[min_index] << " " << moves[min_index] << endl;
    }
}
