#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	unsigned int T, m, f;
	char track[256];
	cin >> T;
	getchar();
	while (T--) {
		m = f = 0;
		cin.getline(track, sizeof(track));
		for (int i = 0; i < strlen(track); i++) {
			if (track[i] == ' ') continue;
			if (track[i] == 'M')  m++;
			else if (track[i] == 'F') f++;
		}
		cout << ((m == f && m > 1) ? "LOOP" : "NO LOOP") <<endl;
	}
	return 0;
}