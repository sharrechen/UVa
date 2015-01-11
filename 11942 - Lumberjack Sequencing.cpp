#include <iostream>

using namespace std;

int main(void) {
	unsigned int T, prev, later;
	bool asc, des;

	cin >> T;
	cout << "Lumberjacks:" << endl;
	while (T--) {
		asc = des = false;
		cin >> prev;
		cin >> later;
		if (prev > later) des = true;
		else asc = true;
		prev = later;
		for (int i = 2; i < 10; i++) {
			cin >> later;
			if (des) {
				if (prev < later) des = false;
			} else if (asc) {
				if (prev > later) asc = false;
			}
			prev = later;
		}
		if (asc || des) cout << "Ordered" <<endl;
		else cout << "Unordered" <<endl;
	}
	return 0;
}