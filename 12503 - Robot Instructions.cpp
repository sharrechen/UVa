#include <stdio.h>

int main(void) {
	unsigned int T, n;
	int x, m, move[128] = {};
	char inst[32];

	scanf("%d\n", &T);
	while (T--) {
		x = 0;
		scanf("%d\n", &n);
		for(int i = 0; i < n; i++) {
			gets(inst);
			if (inst[0] == 'L') {
				move[i] = -1;
				x--;
			} else if (inst[0] == 'R') {
				move[i] = 1;
				x++;
			} else {
				sscanf(inst+8, "%d", &m);
				move[i] = move[m-1];
				x += move[i];
			}
		}
		printf("%d\n", x);
	}
	return 0;
}