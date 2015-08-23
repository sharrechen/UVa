#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    int g;
    string str;

    while (cin >> g, g) {
        cin >> str;
        int glen = str.size() / g;
        string::iterator it = str.begin();
        for (int i = 0; i < g; ++i) {
            reverse(it, it + glen);
            it += glen;
        }
        cout << str << endl;
    }
    return 0;
}