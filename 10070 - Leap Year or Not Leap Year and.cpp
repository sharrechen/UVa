// learn to write clear and simple logic, because it's easier to maintain.
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	int mod4, mod100, mod400, mod15, mod55;
	bool isNotFirst = false, isLead, isOrd;

	while (cin >> input) {
		isLead = false;
		isOrd = true;
		mod4 = mod100 = mod400 = mod15 = mod55 = 0;
		for (size_t i = 0; i < input.length(); ++i) {
			mod4 = (mod4 * 10 + (input[i] - '0')) % 4;
			mod100 = (mod100 * 10 + (input[i] - '0')) % 100;
			mod400 = (mod400 * 10 + (input[i] - '0')) % 400;
			mod15 = (mod15 * 10 + (input[i] - '0')) % 15;
			mod55 = (mod55 * 10 + (input[i] - '0')) % 55;
		}

		if (isNotFirst) cout << endl;
		isNotFirst = true;

		if ((mod4 == 0 && mod100 != 0) || mod400 == 0) {
			isLead = true;
			isOrd = false;
			cout << "This is leap year." << endl;
		}

		if (mod15 == 0) {
			isOrd = false;
			cout << "This is huluculu festival year." << endl;
		}

		if (isLead && mod55 == 0) {
			isOrd = false;
			cout << "This is bulukulu festival year." << endl;
		}

		if (isOrd) {
			cout << "This is an ordinary year." << endl;
		}
	}

	return 0;
}
