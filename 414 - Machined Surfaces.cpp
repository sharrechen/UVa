#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    int r;
    string str;

    while (cin >> r, r) {
        getline(cin, str);
        int sum, min = 32;
        for (int t = sum = 0; t < r; ++t) {
            getline(cin, str);
            int cnt = count(str.begin(), str.begin() + 25, ' ');
            if (cnt < min) min = cnt;
            sum += cnt;
        }
        sum -= min * r;
        cout << sum << endl;
    }

    return 0;
}