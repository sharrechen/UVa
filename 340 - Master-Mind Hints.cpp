#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void) {
	int N, h, w, digit, no = 1, answer[16] = {}, record[16] = {};
	char secret[2048], guess[2048];

	while (cin >> N, N) {
		cout << "Game " << no++ << ":" <<endl;
		getchar();
		gets(secret);
		
		for (int i = 0; i < strlen(secret); i += 2) {
			answer[secret[i] - '0']++;
		}
		while (gets(guess), guess[0] != '0') {
			w = h = 0;
			for (int i = 0; i < strlen(guess); i += 2) {
				digit = guess[i] - '0';
				if (secret[i] == guess[i]) {
					h++;
					record[digit]++;
				}
			}
			for (int i = 0; i < strlen(guess); i += 2) {
				digit = guess[i] - '0';
				if (secret[i] == guess[i] ) continue;
				else if (strchr(secret, guess[i]) != NULL && record[digit] < answer[digit]) {
					w++;
					record[digit]++;
				}
			}
			cout << "    (" << h << "," << w << ")" <<endl;
			memset(record, 0, sizeof(record));
		}
		memset(answer, 0, sizeof(answer));
	}

	return 0;
}