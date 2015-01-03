#include <stdio.h>

int main(void) {
	int t, n, p, min, max;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		min = 99;
		max = 0;
		while (n--) {
			scanf("%d", &p);
			if (p > max) max = p;
			if (p < min) min = p;
		}
		printf("%d\n", 2 * (max - min));
	}
}