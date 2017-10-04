#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, Q, q;

    cin >> N;
    vector<int> ladies(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> ladies[i];
    }
    cin >> Q;
    while (Q--) {
        cin >> q;
        vector<int>::iterator taller, it;
        taller = it = lower_bound(ladies.begin(), ladies.end(), q);
        if (it != ladies.begin()) cout << *(it - 1) << " ";
        else cout << "X ";
        while (taller != ladies.end() && *taller == q) {
            taller++;
        }
        if (taller != ladies.end()) cout << *taller << endl;
        else cout << "X" << endl;
    }

    return 0;
}
