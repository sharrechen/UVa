#include <iostream>
#include <iomanip>

using namespace std;

bool isPl(int *h, int *m) {
	// find first non-zero number to compare
	if (*h) {
		if (*h < 10) {
			if (*h == (*m % 10)) {
				return true;
			} else {
				return false;
			}
		} else {
			if (*h / 10 == *m % 10 && 
				*h % 10 == *m / 10) {
				return true;
			} else {
				return false;
			}
		}
	} else {
		if (*m < 10) {
			return true;
		} else {
			if (*m / 10 == *m % 10) {
				return true;
			} else {
				return false;
			}
		}
	}
}

int main(void) {
	int t, hh, mm;
	char c;
	bool flag;

	cin >> t;
	while (t--) {
		cin >> hh >> c >> mm;
		flag = false;
		for (int h = hh; h <= 24; ++h) {
			if (h == 24) h = 0;
			for (int m = mm + 1; m < 60; ++m) {
				if (isPl(&h, &m)) {
					hh = h;
					mm = m;
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			} else {
				mm = -1;
			}
		}
		cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm <<endl;
	}

	return 0;
}