#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
	int right, left, top, bottom, c, r, t = 1, sweeper[10000] = {0};
	char mine[128][128];

	while (scanf("%d %d\n", &r, &c), r) {
		for (int i = 0; i < r; i++){
			gets(mine[i]);
			for (int j = 0; j < c; j++) {
				if (mine[i][j] == '*') {
					sweeper[i * c + j] = -1;
					right = i * c + j + 1;
					left = i * c + j - 1;
					top = i * c + j - c;
					bottom = i * c + j + c;
					// right
					if (sweeper[right] != -1 && right % c)
						sweeper[right]++;
					// left
					if (sweeper[left] != -1 && left % c != (c - 1) && left >= 0)
						sweeper[left]++;
					// top
					if (sweeper[top] != -1 && top >= 0)
						sweeper[top]++;
					// bottom
					if (sweeper[bottom] != -1 && bottom < r * c)
						sweeper[bottom]++;
					// top right
					if (sweeper[top + 1] != -1 && (top + 1) >= 0 && (top + 1) % c)
						sweeper[top + 1]++;
					// top left
					if (sweeper[top - 1] != -1 && (top - 1) >= 0 && (top - 1) % c != (c - 1))
						sweeper[top - 1]++;
					// bottom right
					if (sweeper[bottom + 1] != -1 && (bottom + 1) < r * c && (bottom + 1) % c)
						sweeper[bottom + 1]++;
					// bottom left
					if (sweeper[bottom - 1] != -1 && (bottom - 1) < r * c && (bottom - 1) % c != (c - 1))
						sweeper[bottom - 1]++;
				}
			}
		}
		if (t > 1) cout <<endl;
		cout << "Field #" << t++ << ":" <<endl;
		for(int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (sweeper[i * c + j] != -1) {
					cout << sweeper[i * c + j];
				} else {
					cout << "*";
				}
			}
			cout <<endl;
		}
		memset(sweeper, 0, sizeof(sweeper));
	}

	return 0;
}