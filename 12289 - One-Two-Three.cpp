#include <iostream>

using namespace std;

int main(void) {
	int T, one, two;
	string number;
	cin >> T;
	while (T--) {
		cin >> number;
		switch (number.length()){
			case 3:
				one = two = 0;
				if (number.at(0) == 'o') one++;
				else two++;
				if (number.at(1) == 'n') one++;
				else two++;
				if (number.at(2) == 'e') one++;
				else two++;
				if (one > two) cout << 1 <<endl;
				else cout << 2 <<endl;
				break;
			case 5:
				cout << 3 <<endl;
				break;
		}
	}

	return 0;
}