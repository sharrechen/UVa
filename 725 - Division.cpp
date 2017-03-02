#include <iostream>
#include <iomanip>
using namespace std;

void useDigits(int number, int & used) {
    while (number) {
        used |= 1 << (number % 10); // record used digit
        number /= 10;
    }
    return;
}

int main(void) {
    int N;

    cin >> N;
    while (N) {
        bool solved = false;
        for (int fghij = 1234; fghij <= 98765 / N; ++fghij) {
            int abcde = fghij * N;
            int used = (fghij < 10000); // record if use 0 digit
            useDigits(abcde, used);
            useDigits(fghij, used);
            if (used == (1 << 10) - 1) { // if use all digits, that means all different digits are used
                cout << abcde << " / " << setfill('0') << setw(5) << fghij << " = " << N << endl;
                solved = true;
            }
        }
        if (!solved) {
            cout << "There are no solutions for " << N << "." << endl;
        }

        cin >> N;
        if (N) cout << endl;
    }

    return 0;
}