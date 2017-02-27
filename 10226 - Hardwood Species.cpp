#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(void) {
    int c;
    string s;
    map<string, int>::iterator itr;

    cin >> c;
    getchar();
    getline(cin, s);
    while (c--) {
        int n = 0;
        map<string, int> trees;
        while(getline(cin, s) && !s.empty()) {
            ++n;
            ++trees[s];
        }

        for (itr = trees.begin(); itr != trees.end(); ++itr) {
            cout << itr->first << " " << fixed << setprecision(4) << (itr->second * 100.0 / n) << endl;
        }
        if (c) cout << endl;
    }

    return 0;
}