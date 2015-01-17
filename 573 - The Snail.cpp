#include <iostream>

using namespace std;

int main(void) {
	double height, up, down, fatigue, tire, total;

	while(cin >> height >> up >> down >> fatigue, height) {
		total = 0;
		tire = up * fatigue / 100.0;
		for (int day = 1;; day++) {
			total += up;
			if (total > height) {
				cout << "success on day " << day <<endl;
				break;
			}
			total -= down;
			if (total < 0 ) {
				cout << "failure on day " << day <<endl;
				break;
			}
			up -= tire;
			if (up < 0) up = 0;
		}

	}
	return 0;
}