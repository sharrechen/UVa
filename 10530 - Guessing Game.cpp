#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
	int guess;
	string response;
	bool record[16];

	memset(record, 1, sizeof(record));
	while (cin >> guess, guess) {
		cin.ignore();
		getline(cin, response);
		
		if (response[4] == 'h') {
			for (int i = guess; i <= 10; ++i) {
					record[i] = false;
			}
		} else if (response[4] == 'l') {
			for (int i = guess; i >= 1; --i) {
					record[i] = false;
			}

		} else if (response[0] == 'r') {
			if (record[guess]) {
				cout << "Stan may be honest" <<endl;
			} else {
				cout << "Stan is dishonest" <<endl;
			}
			memset(record, 1, sizeof(record));
		}
	}

	return 0;
}