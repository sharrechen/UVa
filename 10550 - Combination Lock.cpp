#include <stdio.h>

int main(void) {
	int d1, d2, d3, d4;
	int degree;
	while(scanf("%d %d %d %d", &d1, &d2, &d3, &d4), (d1 || d2 || d3 || d4)) {
		degree = 120;
		degree += (40 + d1 - d2) % 40;
		degree += (40 + d3 - d2) % 40;
		degree += (40 + d3 - d4) % 40;
		printf("%d\n", degree * 9);
	}
}