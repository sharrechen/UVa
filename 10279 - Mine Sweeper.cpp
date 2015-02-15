#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int ngame, size;
	int board[16][16] = {0};
	char mark, mines[16][16];
	bool isDie;

	cin >> ngame;
	while (ngame--) {
		cin >> size;
		for (int r = 0; r < size; ++r) {
			for (int c = 0; c < size; ++c) {
				cin >> mines[r][c];
				if (mines[r][c] == '*') {
					board[r][c] = -1;
				}
			}
		}

		isDie = false;
		for (int r = 0; r < size; ++r) {
			for (int c = 0; c < size; ++c) {
				cin >> mark;
				if (mark == 'x') {
					if (mines[r][c] == '*') {
						isDie = true;
					} else {
						for (int j = (r > 0) ? r - 1 : 0; j < size && j <= r + 1; ++j) {
							for (int k = (c > 0) ? c - 1 : 0; k < size && k <= c + 1; ++k) {
								if (board[j][k] == -1)
									board[r][c]++;
							}
						}						
					}
					mines[r][c] = 'x';
				} 
			}
		}
		
		for (int r = 0; r < size; ++r) {
			for (int c = 0; c < size; ++c) {
				if (mines[r][c] == 'x') {
					if (board[r][c] == -1) cout << '*';
					else cout << board[r][c];
				} else {
					cout << (isDie && board[r][c] == -1 ? '*' : '.');
				}
			}
			cout <<endl;
		}
		if (ngame) cout <<endl;
		memset(board, 0, sizeof(board));
	}

	return 0;
}