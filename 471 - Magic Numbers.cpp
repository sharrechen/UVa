#include <iostream>
using namespace std;

bool uniqueDigits(long long num) {
    int used = false;
    while (num) {
        if (used & (1 << (num % 10))) {
            return false;
        } else {
            used |= 1 << (num % 10);
            num /= 10;
        }
    }
    return true;
}

int main(void) {
    int t;
    long long n;

    cin >> t;
    while (t--) {
        cin >> n;
        // according to the problem, the greatest magic number can only be 9876543210.
        for (long long i = 1; i * n <= 9876543210; ++i) {
            if (uniqueDigits(i) && uniqueDigits(i * n)) {
                cout << i * n << " / " << i << " = " << n << endl;
            }
        }
        if (t) {
            cout << endl;
        }
    }

    return 0;
}
