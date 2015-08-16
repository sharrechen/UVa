#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, no = 0;
    vector<int> stacks(50);

    while (cin >> n, n) {
        int avg = 0;
        for (int i = 0; i < n; ++i) {
            cin >> stacks[i];
            avg += stacks[i];
        }
        avg /= n;
        int min = 0;
        for (int i = 0; i < n; ++i) {
            if (stacks[i] > avg) min += stacks[i] - avg;
        }
        cout << "Set #" << ++no << endl;
        cout << "The minimum number of moves is " << min << "." << endl << endl;
    }

    return 0;
}