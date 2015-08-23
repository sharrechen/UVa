#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    int n;

    cout.setf(ios::fixed);
    cin >> n;
    cin.ignore();
    
    while (n--) {
        int k, m;
        vector<int> price(256, 0);
        cin >> k;
        cin.ignore();
        for (int i = 0; i < k; ++i) {
            char c;
            int v;
            cin >> c >> v;
            cin.ignore();
            price[c] = v;
        }
        cin >> m;
        cin.ignore();
        int pay = 0;
        while (m--) {
            string s;
            getline(cin, s);
            for (size_t l = 0; l < s.size(); ++l) {
                pay += price[s[l]];
            }
        }
        cout << setprecision(2) << pay / 100.0 << "$" << endl;
    }
    return 0;
}