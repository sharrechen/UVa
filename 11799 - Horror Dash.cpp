#include <iostream>

using namespace std;

int main(void) {
	unsigned int T, n, speed, max;
	int i = 1;
	cin >> T;
	while (T--) {
		cin >> n;
		max = 0;
		while (n--) {
			cin >> speed;
			if (speed > max) max = speed;
		}
		cout << "Case " << i++ << ": " << max <<endl;
	}
	return 0;
}