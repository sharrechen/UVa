#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int M;

bool cmp(const int & a, const int & b) {
    if (a % M != b % M) {
        return a % M < b % M;
    }
    if (a & 1) {
        if (b & 1) {
            return a > b;
        }
        return true;
    }
    if (b & 1) {
        return false;
    }
    return a < b;
}

int main(void) {
    int N;
    while (cin >> N >> M) {
        cout << N << " " << M << endl;
        if (!N) {
            break;
        }
        vector<int> numbers(N);
        for (size_t i = 0; i < N; ++i) {
            cin >> numbers[i];
        }
        sort(numbers.begin(), numbers.begin() + N, cmp);
        copy(numbers.begin(), numbers.begin() + N, ostream_iterator<int>(cout, "\n"));
    }
    return 0;
}
