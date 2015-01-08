#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
	unsigned int T, L, H, W;
	int i = 1;
	cin >> T;
	while (T--) {
		cin >> L >> H >> W;
		if (L > 20 || H > 20 || W > 20) {
			printf("Case %d: bad\n", i++);
		} else {
			printf("Case %d: good\n", i++);
		}
	}
	return 0;
}