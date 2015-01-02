#include <stdio.h>

int main(void) {
	unsigned int TC, a, b;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		if (a > b) {
			printf("%c\n", '>');
		} else if (a < b) {
			printf("%c\n", '<');
		} else {
			printf("%c\n", '=');
		}
	}
}