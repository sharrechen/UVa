#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(void) {
    int n, m, t = 1;

    while (cin >> n, n) {
        vector<int> numbers(n);
        for (size_t i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        sort(numbers.begin(), numbers.end());
        cout << "Case " << t++ << ":" << endl;
        cin >> m;
        while (m--) {
            int q, sum, cloz = INT_MAX;
            cin >> q;
            for (size_t i = 0, j = numbers.size() - 1; i != j;) {
                if (abs(q - numbers[i] - numbers[j]) < cloz) {
                    sum = numbers[i] + numbers[j];
                    cloz = abs(q - sum);
                    if (sum == q) break;
                }
                if (numbers[i] + numbers[j] < q) {
                    ++i;
                } else {
                    --j;
                }
            }
            cout << "Closest sum to " << q << " is " << sum << "." << endl;
        }
    }
    
    return 0;
}