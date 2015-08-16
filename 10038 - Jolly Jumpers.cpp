#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main(void) {
    int n;

    while (cin >> n) {
        int a, b;
        bool isJolly = true;
        bitset<3001> check;
        cin >> a;
        for (int i = 1; i < n; ++i) {
            cin >> b;
            int diff = abs(b - a);
            if (!check[diff] && diff < n) {
                check[diff] = true;
            } else {
                isJolly = false;
            }
            a = b;
        }
        cout << (isJolly ? "Jolly" : "Not jolly") << endl;
    }
    return 0;
}