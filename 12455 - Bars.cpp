#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t;

    cin >> t;
    while (t--) {
        bool possible = false;
        int n, p;
        
        cin >> n;
        cin >> p;
        vector<int> lens(p);
        for (size_t i = 0; i < p; ++i) {
            cin >> lens[i];
        }
        for (int i = 0; i < (1 << p); ++i) { // try all p bars used or not situation 
            int sum = 0;
            for (int j = 0; j < p; ++j) {
                if (i & (1 << j)) {
                    sum += lens[j];
                }
            }
            if (sum == n) {
                possible = true;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}