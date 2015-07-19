#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int h, m;
	char c;

	cout.precision(3);
	cout.setf(ios::fixed, ios::floatfield);
	while (cin >> h >> c >> m, h | m) {
		h *= 30;
		double angle = fabs(h + m * 0.5 - m * 6.0); // (h * 30 + m * 0.5) - (m * 6)
		cout << (angle < 180.0 ? angle : 360.0 - angle) << endl;
	}

	return 0;
}