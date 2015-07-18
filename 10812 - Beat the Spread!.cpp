#include <iostream>

using namespace std;

int main(void) {
	unsigned int t, sum, diff;

	cin >> t;
	while (t--) {
		cin >> sum >> diff;
		int s1 = sum + diff, // (a + b) + (a - b)
			s2 = sum - diff; // (a + b) - (a - b)
		if (sum < diff || s1 & 1) {
			cout << "impossible" << endl;
		} else {
			cout << (s1 >> 1) << " " << (s2 >> 1) << endl;
		}
	}

	return 0;
}