#include <iostream>

using namespace std;

int main(void) {
	char highway[2097152];
	int L, min, r, d;

	while (scanf("%d\n", &L), L) {
		cin.getline(highway, sizeof(highway));
		r = d = min = 2097152;
		for (int i = 0; i < L; i++) {
			if (highway[i] == '.') continue;
			if (highway[i] == 'Z') {
				min = 0;
				break;
			} else if (highway[i] == 'R') {
				r = i;
				if (abs(r-d) < min) min = abs(r-d);
			} else if (highway[i] == 'D') {
				d = i;
				if (abs(r-d) < min) min = abs(r-d);
			}
		}
		cout << min <<endl;
	}

	return 0;
}