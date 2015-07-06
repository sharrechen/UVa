#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int t;
    string str;

    cin >> t;
    while (t--) {
        cin >> str;
        sort(str.begin(), str.end());
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));
        cout << endl;
    }

    return 0;
}