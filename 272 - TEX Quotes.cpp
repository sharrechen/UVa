#include <stdio.h>

int main(void) {
	char c;
	char q = '"';
	int num = 1;
	while (scanf("%c", &c) != EOF) {
		if (c == q) {
			if (num++ & 1) {
				printf("%s", "``");
			} else {
				printf("%s", "''");
			}
		} else {
			printf("%c", c);
		}
	}
}