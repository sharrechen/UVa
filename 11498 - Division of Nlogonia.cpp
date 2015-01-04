#include <stdio.h>

int main(void) {
	int TC, div_x, div_y, x, y;

	scanf("%d", &TC);
	while (TC != 0) {
		scanf("%d %d", &div_x, &div_y);
		while (TC--) {
			scanf("%d %d", &x, &y);
			if (x == div_x || y == div_y) {
				printf("divisa\n");
			} else if (x < div_x) {
				if (y > div_y) {
					printf("NO\n");
				} else {
					printf("SO\n");
				}
			} else {
				if (y > div_y) {
					printf("NE\n");
				} else {
					printf("SE\n");
				}
			}
		}
		scanf("%d", &TC);
	}

	return 0;
}